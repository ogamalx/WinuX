# Building WinuX

WinuX is a bootable USB creation tool based on UNetbootin. This guide covers building on both Windows and Linux.

## Windows Build (Recommended for Testing)

### Quick Build with PowerShell

The easiest way to build and test WinuX on **Windows 10/11 x64** is using the provided PowerShell script:

```powershell
# Run from project root directory (requires PowerShell 5.1+)
.\test-build.ps1
```

This script will automatically:
- Detect Visual Studio installation
- Install Qt 5.15.2 via aqtinstall (if needed)
- Configure and build the project with MSVC
- Output the executable to `src\unetbootin\release\unetbootin.exe`

### PowerShell Script Options

```powershell
# Clean build (removes previous build artifacts)
.\test-build.ps1 -Clean

# Use custom Qt installation path
.\test-build.ps1 -QtPath "D:\Qt"

# Skip Qt installation if already installed
.\test-build.ps1 -SkipQtInstall

# Specify Qt version
.\test-build.ps1 -QtVersion "5.15.2"
```

### Windows Build Requirements

- **Windows 10/11 x64**
- **Visual Studio 2019 or 2022** with "Desktop development with C++" workload
- **Python 3.x** (for aqtinstall Qt installer)
- PowerShell 5.1 or later

### Manual Windows Build

If you prefer to build manually:

1. Install Visual Studio 2019/2022 with C++ build tools
2. Install Python 3.x and add to PATH
3. Install Qt:
   ```powershell
   pip install aqtinstall
   python -m aqt install-qt --outputdir C:\Qt windows desktop 5.15.2 win64_msvc2019_64 --archives qtbase qttools
   ```
4. Open "x64 Native Tools Command Prompt for VS"
5. Navigate to project and build:
   ```cmd
   cd src\unetbootin
   set PATH=C:\Qt\5.15.2\msvc2019_64\bin;%PATH%
   qmake CONFIG+=release unetbootin.pro
   nmake
   ```

---

## Linux Build

### Quick Build with Bash

From the project root directory:

```bash
chmod +x test-build.sh
./test-build.sh
```

This script will automatically:
- Install Qt5 development tools
- Generate translation files
- Generate UI headers
- Build the project

### Build in GitHub Codespaces (Interactive)

1. Go to your repo `ogamalx/WinuX` → Code → Codespaces → Create codespace
2. When VS Code opens in the browser, open a terminal
3. Run the build script from the project root:
   ```bash
   ./test-build.sh
   ```

### Manual Linux Build

1. Install Qt development tools:
   ```bash
   sudo apt update
   sudo apt install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools qttools5-dev-tools
   ```
2. Navigate to the source directory and build:
   ```bash
   cd src/unetbootin
   qmake unetbootin.pro
   make -j"$(nproc)"
   ```

If the build completes without errors, ✅ all code compiles on a clean Linux environment.

### Linux Build Requirements

- Qt 5.x development libraries
- qmake
- C++ compiler (g++ or clang)
- Linux environment (Ubuntu 20.04+ recommended)

---

## Automated Build (GitHub Actions)

The repository includes GitHub Actions workflows that automatically:

| Workflow | Platform | Trigger |
|----------|----------|---------|
| `build.yml` | Linux (Ubuntu) | Every push and PR |
| `windows-build.yml` | Windows | Push/PR to master |

This ensures code quality and catches build-breaking changes automatically.

---

## Testing

### Windows Testing

After building on Windows, you can test the tool:

1. Run `src\unetbootin\release\unetbootin.exe` as Administrator
2. Select a Linux distribution ISO or disk image
3. Choose target USB drive
4. Create the bootable USB

> **Note**: Creating bootable USB drives requires Administrator privileges.

### Linux Testing

The Linux build is primarily for compile-time validation. Full runtime testing of USB creation functionality requires Windows.

---

## Troubleshooting

### Windows Issues

| Issue | Solution |
|-------|----------|
| "vswhere.exe not found" | Install Visual Studio 2019/2022 with C++ tools |
| "Python not found" | Install Python 3.x from python.org and add to PATH |
| "Qt not found" | Run `test-build.ps1` without `-SkipQtInstall` |
| Permission errors | Run PowerShell as Administrator |

### Linux Issues

| Issue | Solution |
|-------|----------|
| "qmake not found" | Install `qtbase5-dev` and `qt5-qmake` |
| "uic not found" | Install `qttools5-dev-tools` |
| Compiler errors | Ensure `build-essential` is installed |
