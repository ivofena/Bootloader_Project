copy ..\..\Bootloader\build\libboot.a ..\lib 2>&1 | dos2unix | tee make.log
make -f makefile clean all 2>&1 | dos2unix | tee make.log
call e.bat

