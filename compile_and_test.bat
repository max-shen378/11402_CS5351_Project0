@echo off
cd /d C:\Users\maxsh\AI_Assisted_SD\11402_CS5351_Project0
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat" x64
echo.
echo === Compiling Test Suite ===
cl /EHsc /std:c++17 src\test_cases.cpp src\twosum.cpp /Fe:test_runner.exe
echo.
if exist test_runner.exe (
    echo === Running Tests ===
    test_runner.exe
) else (
    echo ERROR: Compilation failed
)
