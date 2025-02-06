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

echo === Generation de la documentation Doxygen ===
doxygen Doxyfile
if %errorlevel% neq 0 exit /b %errorlevel%

echo === Creation du fichier Documentation.html ===
(
    echo ^<meta http-equiv="REFRESH" content="0;URL=html/index.html"^>
) > doc\Documentation.html
if %errorlevel% neq 0 exit /b %errorlevel%

echo === Compilation termine avec succes ! ===
pause
