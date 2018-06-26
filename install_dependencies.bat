@echo off

if not exist windows_dependencies mkdir windows_dependencies
if exist windows_dependencies/odb exit /b
cd windows_dependencies

curl -o libodb-2.4.0.zip https://www.codesynthesis.com/download/odb/2.4/libodb-2.4.0.zip
unzip libodb-2.4.0.zip
move libodb-2.4.0\odb .\

curl -o libodb-sqlite-2.4.0.zip https://www.codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.zip
unzip libodb-sqlite-2.4.0.zip
move libodb-sqlite-2.4.0\odb\sqlite odb\

dir
cd ..
