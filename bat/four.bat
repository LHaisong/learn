@echo off
xcopy D:\learn\bat\first.bat D:\learn\bat\test\copyfirst.bat
if errorlevel 1 echo copy file fail
if errorlevel 0 echo copy file success