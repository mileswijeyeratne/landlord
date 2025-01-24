@echo off
set BUILD_DIR=build
set CONFIG=Release
set TARGET=%1

:: ensure target is valid
if "%TARGET%" neq "server" (
    if "%TARGET%" neq "client" (
        echo Error: Target is neither 'client' nor 'server'
        exit /b 1
    )
)

:: ensure build dir exists
if not exist %BUILD_DIR% (
    mkdir %BUILD_DIR%
)
cd %BUILD_DIR%

:: config CMake
cmake .. -G "Visual Studio 17 2022" -A x64
if %errorlevel% neq 0 (
    echo CMake configuration failed!
    exit /b %errorlevel%
)

:: build common tests
cmake --build . --config %CONFIG% --target common_tests
if %errorlevel% neq 0 (
	echo Common tests failed to build!
    exit /b %errorlevel%
)

:: run common tests
echo Running tests...
common\%CONFIG%\common_tests.exe
if %errorlevel% neq 0 (
	echo Common tests failed!
    exit /b %errorlevel%
) else (
	echo All tests passed!
)

:: build target
cmake --build . --config %CONFIG% --target %TARGET%
if %errorlevel% neq 0 (
    echo Client build failed!
    exit /b %errorlevel%
)

echo Build completed successfully!
exit /b 0
