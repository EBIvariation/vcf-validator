@echo off

if not exist windows_dependencies mkdir windows_dependencies
if exist windows_dependencies/odb exit /b
cd windows_dependencies

:: Download zip files
curl -o libodb-2.4.0.zip https://www.codesynthesis.com/download/odb/2.4/libodb-2.4.0.zip
curl -o libodb-sqlite-2.4.0.zip https://www.codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.zip
curl -o sqlite-dll.zip https://www.sqlite.org/2018/sqlite-dll-win32-x86-3240000.zip
curl -o sqlite-amalgamation.zip https://www.sqlite.org/2018/sqlite-amalgamation-3240000.zip

:: Unzip zip files
powershell -command "Expand-Archive libodb-2.4.0.zip ."
powershell -command "Expand-Archive libodb-sqlite-2.4.0.zip ."
powershell -command "Expand-Archive sqlite.zip ."
powershell -command "Expand-Archive sqlite-amalgamation.zip ."

:: Restructure Directory
move libodb-sqlite-2.4.0\etc\sqlite .\
move sqlite3.def .\sqlite\
move sqlite-amalgamation-3240000\sqlite3.c .\sqlite\
move sqlite-amalgamation-3240000\sqlite3.h .\sqlite\

:: copy headers
xcopy /e/i libodb-2.4.0\odb .\odb\
xcopy /e/i libodb-sqlite-2.4.0\odb\sqlite odb\sqlite\

:: Delete useless files
del libodb-2.4.0.zip
del libodb-sqlite-2.4.0.zip
del sqlite-dll.zip
del sqlite-amalgamation.zip
del sqlite3.dll
rmdir /s /q sqlite-amalgamation-3240000

dir
cd ..
