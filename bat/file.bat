@echo off
::echo this is file additional write > D:\learn\bat\test.txt
::echo +++++++++++++++++++++ >> D:\learn\bat\test.txt
::dir c:\ >> D:\learn\bat\test.txt
FOR /F "tokens=* delims=" %%x in (test.txt) DO echo %%x