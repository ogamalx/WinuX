#!/bin/bash
set -e

echo "Installing Qt5 development tools..."
sudo apt install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools

echo "Building WinuX..."
cd src/unetbootin
qmake unetbootin.pro
make -j"$(nproc)"

echo "Build completed successfully!"
