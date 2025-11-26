#!/bin/bash
set -e

echo "Installing Qt5 development tools..."
sudo apt install -y qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools qttools5-dev-tools

echo "Building WinuX..."
cd src/unetbootin

echo "Generating translation files..."
for ts_file in *.ts; do 
    lrelease "$ts_file" -qm "${ts_file%.ts}.qm"
done

echo "Generating UI headers..."
uic unetbootin.ui -o ui_unetbootin.h

echo "Building project..."
qmake unetbootin.pro
make -j"$(nproc)"

echo "Build completed successfully!"
