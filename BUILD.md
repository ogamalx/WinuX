# Building WinuX

## Quick Build (Recommended)

The easiest way to build WinuX is using the provided build script.

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

## Build in GitHub Codespaces (Interactive)

1. Go to your repo `ogamalx/WinuX` → Code → Codespaces → Create codespace
2. When VS Code opens in the browser, open a terminal
3. Run the build script from the project root:
   ```bash
   ./test-build.sh
   ```

Alternatively, you can build manually:
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

## Automated Build (GitHub Actions)

The repository includes a GitHub Actions workflow (`.github/workflows/build.yml`) that automatically:
- Builds WinuX on every push and pull request
- Runs on Ubuntu with Qt5
- Shows build status with ✅ or ❌ on PRs

This ensures code quality and catches build-breaking changes automatically.

## Build Requirements

- Qt 5.x development libraries
- qmake
- C++ compiler (g++ or clang)
- Linux environment (Ubuntu 20.04+ recommended)

## Notes

The Codespaces/CI build is for compile-time validation only. Runtime testing requires Windows to test the actual bootable USB creation functionality.
