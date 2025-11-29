<#
.SYNOPSIS
    WinuX Build Script for Windows 10/11 x64

.DESCRIPTION
    This PowerShell script automates the build process for WinuX on Windows.
    It installs Qt via aqtinstall, sets up MSVC, and builds the project.

.PARAMETER QtVersion
    Qt version to install (default: 5.15.2)

.PARAMETER QtPath
    Path where Qt will be installed (default: C:\Qt)

.PARAMETER Clean
    Clean build artifacts before building

.PARAMETER SkipQtInstall
    Skip Qt installation if already installed

.EXAMPLE
    .\test-build.ps1
    
.EXAMPLE
    .\test-build.ps1 -Clean -QtPath "D:\Qt"

.NOTES
    Requires:
    - Windows 10/11 x64
    - Visual Studio 2019 or 2022 with C++ build tools
    - Python 3.x (for aqtinstall)
    - Administrator privileges may be required for some operations
#>

[CmdletBinding()]
param(
    [string]$QtVersion = "5.15.2",
    [string]$QtPath = "C:\Qt",
    [switch]$Clean,
    [switch]$SkipQtInstall
)

$ErrorActionPreference = "Stop"

function Write-Status {
    param([string]$Message, [string]$Color = "Cyan")
    Write-Host "==> $Message" -ForegroundColor $Color
}

function Write-Success {
    param([string]$Message)
    Write-Host "[OK] $Message" -ForegroundColor Green
}

function Write-Failure {
    param([string]$Message)
    Write-Host "[FAIL] $Message" -ForegroundColor Red
}

function Test-Command {
    param([string]$Command)
    $null = Get-Command $Command -ErrorAction SilentlyContinue
    return $?
}

function Find-VSWhere {
    $vswhereDefault = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    if (Test-Path $vswhereDefault) {
        return $vswhereDefault
    }
    
    # Try to find vswhere in PATH
    if (Test-Command "vswhere") {
        return "vswhere"
    }
    
    return $null
}

function Get-VSInstallPath {
    $vswhere = Find-VSWhere
    if (-not $vswhere) {
        throw "vswhere.exe not found. Please install Visual Studio 2019 or 2022 with C++ build tools."
    }
    
    $installPath = & $vswhere -latest `
        -products * `
        -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 `
        -property installationPath
    
    if (-not $installPath) {
        throw "Visual Studio with C++ build tools not found."
    }
    
    return $installPath
}

function Get-VCVarsPath {
    $vsPath = Get-VSInstallPath
    $vcvarsPath = Join-Path $vsPath "VC\Auxiliary\Build\vcvars64.bat"
    
    if (-not (Test-Path $vcvarsPath)) {
        throw "vcvars64.bat not found at $vcvarsPath"
    }
    
    return $vcvarsPath
}

function Install-QtWithAqt {
    param(
        [string]$Version,
        [string]$OutputDir
    )
    
    Write-Status "Checking Python installation..."
    if (-not (Test-Command "python")) {
        throw "Python is not installed. Please install Python 3.x from https://www.python.org/"
    }
    
    $qtDir = Join-Path $OutputDir "$Version\msvc2019_64"
    
    # Check if Qt is already installed
    if (Test-Path $qtDir) {
        Write-Success "Qt $Version already installed at $qtDir"
        return $qtDir
    }
    
    # Only install aqtinstall if we need to download Qt
    Write-Status "Installing/updating aqtinstall..."
    $pipOutput = python -m pip install --upgrade pip 2>&1
    if ($LASTEXITCODE -ne 0) {
        Write-Host "pip upgrade output: $pipOutput" -ForegroundColor Yellow
    }
    $aqtOutput = python -m pip install aqtinstall 2>&1
    if ($LASTEXITCODE -ne 0) {
        Write-Host "aqtinstall install output: $aqtOutput" -ForegroundColor Yellow
        throw "Failed to install aqtinstall"
    }
    
    Write-Status "Installing Qt $Version (MSVC 2019 x64)..."
    Write-Status "This may take several minutes..."
    
    python -m aqt install-qt --outputdir $OutputDir windows desktop $Version win64_msvc2019_64 `
        --archives qtbase qttools
    
    if ($LASTEXITCODE -ne 0) {
        throw "Failed to install Qt"
    }
    
    Write-Success "Qt $Version installed to $qtDir"
    return $qtDir
}

function Get-MSCVersion {
    param([string]$VCVarsPath)
    
    $cmd = "`"$VCVarsPath`" && cl 2>&1"
    $output = cmd.exe /c $cmd
    
    $match = $output | Select-String -Pattern 'Microsoft.*?Version\s+(\d+)\.(\d+)'
    if (-not $match) {
        throw "Failed to detect MSVC version"
    }
    
    $major = [int]$match.Matches[0].Groups[1].Value
    $minor = [int]$match.Matches[0].Groups[2].Value
    
    return ($major * 100 + $minor)
}

function Invoke-Build {
    param(
        [string]$QtDir,
        [string]$VCVarsPath,
        [int]$MSCVer
    )
    
    $srcDir = Join-Path $PSScriptRoot "src\unetbootin"
    
    if (-not (Test-Path $srcDir)) {
        throw "Source directory not found: $srcDir"
    }
    
    Push-Location $srcDir
    
    try {
        if ($Clean) {
            Write-Status "Cleaning build artifacts..."
            if (Test-Path "Makefile") {
                $cmd = "`"$VCVarsPath`" && nmake clean"
                cmd.exe /c $cmd 2>&1 | Out-Null
            }
            
            # Remove generated files
            @("Makefile", "Makefile.Release", "Makefile.Debug", 
              "ui_unetbootin.h", "moc_*.cpp", "*.o", "*.obj",
              "qrc_*.cpp") | ForEach-Object {
                Get-ChildItem -Path . -Filter $_ -ErrorAction SilentlyContinue | Remove-Item -Force -ErrorAction SilentlyContinue
            }
            
            if (Test-Path "release") {
                Remove-Item -Path "release" -Recurse -Force -ErrorAction SilentlyContinue
            }
            if (Test-Path "debug") {
                Remove-Item -Path "debug" -Recurse -Force -ErrorAction SilentlyContinue
            }
            
            Write-Success "Build artifacts cleaned"
        }
        
        # Add Qt bin to PATH
        $env:PATH = "$QtDir\bin;$env:PATH"
        
        Write-Status "Configuring with qmake..."
        # Set QMAKE_MSC_VER as an environment variable and call qmake in cmd.exe
        # qmake requires QMAKE_MSC_VER to be set as an environment variable, not a command-line parameter
        $qmakeCmd = "`"$VCVarsPath`" && set QMAKE_MSC_VER=$MSCVer && qmake CONFIG+=release unetbootin.pro"
        Write-Host "Running: qmake CONFIG+=release (with QMAKE_MSC_VER=$MSCVer)" -ForegroundColor Gray
        cmd.exe /c $qmakeCmd
        
        if ($LASTEXITCODE -ne 0) {
            throw "qmake configuration failed"
        }
        Write-Success "qmake configuration completed"
        
        Write-Status "Building with nmake..."
        $nmakeCmd = "`"$VCVarsPath`" && nmake /NOLOGO"
        cmd.exe /c $nmakeCmd
        
        if ($LASTEXITCODE -ne 0) {
            throw "nmake build failed"
        }
        Write-Success "Build completed successfully!"
        
        # Check for output
        $exePath = Join-Path $srcDir "release\unetbootin.exe"
        if (Test-Path $exePath) {
            $fileInfo = Get-Item $exePath
            Write-Host ""
            Write-Success "Output: $exePath"
            Write-Host "        Size: $([math]::Round($fileInfo.Length / 1KB, 2)) KB" -ForegroundColor Gray
            Write-Host ""
            return $exePath
        }
        else {
            Write-Failure "Expected output not found at $exePath"
            return $null
        }
    }
    finally {
        Pop-Location
    }
}

# Main execution
try {
    Write-Host ""
    Write-Host "========================================" -ForegroundColor Magenta
    Write-Host "   WinuX Build Script for Windows x64  " -ForegroundColor Magenta
    Write-Host "========================================" -ForegroundColor Magenta
    Write-Host ""
    
    # Check prerequisites
    Write-Status "Checking prerequisites..."
    
    # Check for Visual Studio
    $vcvarsPath = Get-VCVarsPath
    Write-Success "Found Visual Studio: $vcvarsPath"
    
    # Detect MSVC version
    Write-Status "Detecting MSVC version..."
    $mscVer = Get-MSCVersion -VCVarsPath $vcvarsPath
    Write-Success "MSVC version: $mscVer"
    
    # Install/locate Qt
    if (-not $SkipQtInstall) {
        $qtDir = Install-QtWithAqt -Version $QtVersion -OutputDir $QtPath
    }
    else {
        $qtDir = Join-Path $QtPath "$QtVersion\msvc2019_64"
        if (-not (Test-Path $qtDir)) {
            throw "Qt not found at $qtDir. Run without -SkipQtInstall to install Qt."
        }
        Write-Success "Using existing Qt at $qtDir"
    }
    
    # Build the project
    $exePath = Invoke-Build -QtDir $qtDir -VCVarsPath $vcvarsPath -MSCVer $mscVer
    
    if ($exePath) {
        Write-Host "========================================" -ForegroundColor Green
        Write-Host "   BUILD SUCCESSFUL!                   " -ForegroundColor Green
        Write-Host "========================================" -ForegroundColor Green
        Write-Host ""
        Write-Host "To run WinuX:" -ForegroundColor Yellow
        Write-Host "  $exePath" -ForegroundColor White
        Write-Host ""
        Write-Host "Note: You may need to run as Administrator" -ForegroundColor Yellow
        Write-Host "      for USB drive operations." -ForegroundColor Yellow
        Write-Host ""
    }
}
catch {
    Write-Host ""
    Write-Failure "Build failed: $_"
    Write-Host ""
    Write-Host "Troubleshooting tips:" -ForegroundColor Yellow
    Write-Host "1. Ensure Visual Studio 2019/2022 with C++ tools is installed" -ForegroundColor Gray
    Write-Host "2. Ensure Python 3.x is installed and in PATH" -ForegroundColor Gray
    Write-Host "3. Run this script from the project root directory" -ForegroundColor Gray
    Write-Host "4. Try running as Administrator if permission errors occur" -ForegroundColor Gray
    Write-Host ""
    exit 1
}
