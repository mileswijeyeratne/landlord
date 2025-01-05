@echo on

set INITIAL_CWD=%CD%

:: build
call build.bat server
if %ERRORLEVEL% neq 0 (
    echo Error: build.bat failed with code %ERRORLEVEL%.
    echo Exiting without running the server.
    exit /b %ERRORLEVEL%
)

cd %INITIAL_CWD%

:: run server
set SERVER_PATH=build\server\Release\server.exe
echo Running server...
if exist "%SERVER_PATH%" (
    %SERVER_PATH%
) else (
    echo Error: server.exe was not found at %SERVER_PATH%! 
    exit /b 1
)
