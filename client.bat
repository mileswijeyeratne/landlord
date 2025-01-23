@echo on

set INITIAL_CWD=%CD%

:: build
call build.bat client
if %ERRORLEVEL% neq 0 (
    echo Error: build.bat failed with code %ERRORLEVEL%.
    echo Exiting without running the client.
    exit /b %ERRORLEVEL%
)

cd %INITIAL_CWD%

:: run client
set CLIENT_PATH=build\client\Release\client.exe
echo Running client...
if exist "%CLIENT_PATH%" (
    %CLIENT_PATH%
) else (
    echo Error: client.exe was not found at %CLIENT_PATH%! 
    exit /b 1
)
