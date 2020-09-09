@echo off
set globalvar=5
set str=Outer
rem call function
call :Display
call :Sum 5,6
call :SetVal val1,val2
call :FuncLocal str
echo val1 is %val1%,val2 is %val2%,str1 is %str%

EXIT /B %ERRORLEVEL%
rem function defined
:Display
echo the value of globalvar is %globalvar%
EXIT /B 0
rem 带参数的函数
:Sum 
set /A s="%~1+%~2"
echo the sum of two number is %s%
EXIT /B 0
rem 带返回值的函数
:SetVal
set "%~1=5"
set "%~2=10"
EXIT /B 0
rem 函数中的局部变量
:FuncLocal
SETLOCAL
set strlocal=Inner
set "%~1=%strlocal%"
ENDLOCAL
EXIT /B 0