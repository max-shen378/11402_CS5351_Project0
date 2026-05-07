@echo off
cd /d C:\Users\maxsh\AI_Assisted_SD\11402_CS5351_Project0
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" x64
cl /EHsc /I. src\main.cpp src\twosum.cpp /Fe:twosum.exe
echo.
echo Running with test input...
(
echo 4
echo 2 7 11 15
echo 9
) | twosum.exe
