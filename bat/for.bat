@echo off
SETLOCAL ENABLEDELAYEDEXPANSION
::for %%i in (*.*) do echo %%i
set /a sum=0
set /a ii=0
set str= c d e f g h i j k l m n o p q r s t u v w x y z
rem 计算1+2+······+100的值
echo ++++++++++++++++++++计算值++++++++++++++++++++++
for /l %%i in (1,1,100) do (
    set /a ii+=1
    set /a sum+=!ii!
)
echo %sum%

rem 检测硬盘分区
echo ++++++++++++++++++++检测硬盘分区++++++++++++++++++++++
for %%I in (%str%) do (
    if exist %%I: echo %%I:
)
rem 列出当前目录的所有文件
echo ++++++++++++++++++++列出文件++++++++++++++++++++++
for %%I in (*.*) do echo %%I

rem for /f                                                     
echo ++++++++++++++++++++打印文件内容++++++++++++++++++++++
for /f %%I in (testfor.txt) do echo %%I          
echo ++++++++++++++++添加delims,默认参数是空格++++++++++++++++++++++
for /f "delims=" %%I in (c.txt) do echo %%I                                                        
echo ++++++++++++++++添加tokens开关++++++++++++++++++++++
for /f "tokens=2,8" %%I in (c.txt) do echo %%I %%J
echo ++++++++++++++++添加skip开关++++++++++++++++++++++
for /f "delims=； skip=2" %%I in (c.txt) do echo %%I
echo ++++++++++++++++添加eol开关++++++++++++++++++++++
for /f "delims=; eol=2" %%I in (c.txt) do echo %%I

rem for /d
echo ++++++++++++++++++++显示文件夹++++++++++++++++++++++
for /d %%I in (c:\*) do echo %%I
echo ++++++++++++++++++++显示p开头文件夹++++++++++++++++++++++
for /d %%I in (c:\*) do echo %%I

rem for /r
echo +++++++++++++++++++++枚举C盘所有的exe文件++++++++++++++++
for /r C: %%I in (*.exe) do echo %%I
echo +++++++++++++++++++++枚举chrome.exe所在的文件夹++++++++++++++++
for /r C:\ %%I in (Chrome.exe) do if exist %%I echo %%I
pause