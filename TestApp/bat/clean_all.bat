cmake --build ..\..\Bootloader\build --config Debug --target clean --  2>&1 | dos2unix | tee make.log
call e.bat