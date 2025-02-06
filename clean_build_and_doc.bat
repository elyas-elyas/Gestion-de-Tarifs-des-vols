@echo off
echo === Nettoyage des fichiers compiles ===
make clean

echo === Suppression du contenu de la documentation generee par Doxygen ===
if exist doc\html rmdir /s /q doc\html

echo === Suppression du fichier Documentation.html ===
if exist doc\Documentation.html del /q doc\Documentation.html

echo === Nettoyage termine ! ===
pause
