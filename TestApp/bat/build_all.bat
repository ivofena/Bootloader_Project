cmake --build ..\..\Bootloader\build --config Debug --target clean --
cmake -G "MinGW Makefiles" -S ..\..\Bootloader\ -B ..\..\Bootloader\build
cmake --build ..\..\Bootloader\build --config Debug --target boot -- -j 10 
copy ..\..\Bootloader\build\libboot.a ..\lib 
make -f makefile clean all 
call e.bat