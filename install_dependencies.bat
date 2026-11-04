@echo off

:: Target architecture of libcurl (x86 or x64), must match the compiler environment
if "%MACHINE%"=="" set MACHINE=x86

if not exist dependencies mkdir dependencies
cd dependencies

:: Download zip files
powershell -command "(new-object System.Net.WebClient).DownloadFile('https://curl.haxx.se/download/curl-7.62.0.zip','curl-7.62.0.zip')"

:: Unzip zip files
powershell -command "Expand-Archive curl-7.62.0.zip ."

:: Build libcurl
cd curl-7.62.0/winbuild
nmake /f Makefile.vc mode=static VC=15 DEBUG=no RTLIBCFG=static MACHINE=%MACHINE%
cd ../../
md curl\include
md curl\lib

:: Restructure directory

:: Copy headers
xcopy /e/i curl-7.62.0\include\* curl\include

:: Copy libcurl
xcopy curl-7.62.0\builds\libcurl-vc15-%MACHINE%-release-static-ipv6-sspi-winssl-obj-lib\libcurl_a.lib curl\lib
ren curl\lib\libcurl_a.lib libcurl.lib

:: Delete useless files
del curl-7.62.0.zip

dir
cd ..
