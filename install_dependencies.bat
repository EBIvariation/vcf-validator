@echo off

if not exist windows_dependencies mkdir windows_dependencies
cd windows_dependencies

:: Download zip files
powershell -command "(new-object System.Net.WebClient).DownloadFile('https://curl.haxx.se/download/curl-7.62.0.zip','curl-7.62.0.zip')"

:: Unzip zip files
powershell -command "Expand-Archive curl-7.62.0.zip ."

:: Build libcurl
cd curl-7.62.0/winbuild
nmake /f Makefile.vc mode=static VC=15 DEBUG=no RTLIBCFG=static
cd ../../
md curl\include
md curl\lib

:: Restructure directory

:: Copy headers
xcopy /e/i curl-7.62.0\include\* curl\include

:: Copy libcurl
xcopy curl-7.62.0\builds\libcurl-vc15-x86-release-static-ipv6-sspi-winssl-obj-lib\libcurl_a.lib curl\lib
ren curl\lib\libcurl_a.lib libcurl.lib

:: Delete useless files
del curl-7.62.0.zip

dir
cd ..
