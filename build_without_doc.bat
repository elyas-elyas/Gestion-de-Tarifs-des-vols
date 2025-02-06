@echo off
echo === Compilation du projet ===
make
if %errorlevel% neq 0 exit /b %errorlevel%

echo === Execution du programme ===
make run
if %errorlevel% neq 0 exit /b %errorlevel%

echo === Execution des tests ===
make test
if %errorlevel% neq 0 exit /b %errorlevel%

echo === Compilation termine avec succes ! ===
pause
