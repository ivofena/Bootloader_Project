cmake ..
cmake --build ..\build --config Debug --target boot -- -j 10 2>&1 | dos2unix | tee make.log
call e.bat

