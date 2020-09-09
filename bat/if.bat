@echo off 
SET /A a=5 
SET /A b=10
SET /A c=%a% + %b% 
SET str1=string1
SET str2=string2

if %c%==15 (echo "The value of variable c is 15") else (echo "Unknown value") 
if %c%==10 (echo "The value of variable c is 10") else (echo "Unknown value")
if %str1%==string1 (echo "The value of variable String1") else (echo "Unknown value") 
if %str2%==string3 (echo "The value of variable c is String3") else (echo "Unknown value")
if defined str1 (echo "str1 is defined") else (echo "str1 is not defined")
rem if exist常用于判断文件是否存在
if exist D:\learn\bat\bat.md echo file exist

