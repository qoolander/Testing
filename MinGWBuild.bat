rmdir /Q /S build
mkdir build
cmake -S . -B build -G "MinGW Makefiles"
cd build
mingw32-make
windeployqt bin\prog.exe