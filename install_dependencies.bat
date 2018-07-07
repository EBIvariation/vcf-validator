@echo off

if %1'==/?' goto :help

:main
if not exist windows_dependencies mkdir windows_dependencies
if exist windows_dependencies/odb exit /b
cd windows_dependencies

:: Download zip files
powershell -command "(new-object System.Net.WebClient).DownloadFile('https://www.codesynthesis.com/download/odb/2.4/libodb-2.4.0.zip','.\libodb-2.4.0.zip')"
powershell -command "(new-object System.Net.WebClient).DownloadFile('https://www.codesynthesis.com/download/odb/2.4/libodb-sqlite-2.4.0.zip','.\libodb-sqlite-2.4.0.zip')"
powershell -command "(new-object System.Net.WebClient).DownloadFile('https://www.sqlite.org/2018/sqlite-dll-win32-x86-3240000.zip','.\sqlite-dll.zip')"
powershell -command "(new-object System.Net.WebClient).DownloadFile('https://www.sqlite.org/2018/sqlite-amalgamation-3240000.zip','sqlite-amalgamation.zip')"

:: Unzip zip files
ver | findstr /i "10\.0\." > nul && (set use=expand_archive)
if "%use%" == "expand_archive" (
    powershell -command "Expand-Archive libodb-2.4.0.zip ."
    powershell -command "Expand-Archive libodb-sqlite-2.4.0.zip ."
    powershell -command "Expand-Archive sqlite-dll.zip ."
    powershell -command "Expand-Archive sqlite-amalgamation.zip ."
) ELSE (
    unzip libodb-2.4.0.zip
    unzip libodb-sqlite-2.4.0.zip
    unzip sqlite-dll.zip
    unzip sqlite-amalgamation.zip
)

:: Restructure directory
move libodb-sqlite-2.4.0\etc\sqlite .\
move sqlite3.def .\sqlite\
move sqlite-amalgamation-3240000\sqlite3.c .\sqlite\
move sqlite-amalgamation-3240000\sqlite3.h .\sqlite\

:: Copy headers
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

goto :eof

:help
echo Usage:
echo install_dependencies.bat                   run install scripts
echo install_dependencies.bat /?                displays help
echo.
echo it downloads the given dependencies:
echo  - odb common runtime library              libodb-2.4.0
echo  - odb sqlite runtime library              libodb-sqlite-2.4.0
echo.
echo Requires unzip for windows version below 10

