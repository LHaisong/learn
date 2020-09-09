## 1.常见的批处理命令
| 编号 | 命令 | 描述 |
| ---- | ---- | ----- |


## 2.批处理语法
```
@echo off 
Rem This is for listing down all the files in the directory Program files 
dir "C:\Program Files" > C:\lists.txt 
echo "The program has completed"
```
- 批处理程序一般以@echo off开头，表示执行代码时不显示命令
- rem用于编写注释，说明批处理的功能
- dir用于获取目录的内容
- ">" 将命令输出到指定的目录

## 3.批处理参数与变量
批处理文件还可以像C语言的函数一样使用参数（相当于DOS命令的命令行参数），这需要用到一个参数表示符“%”。%[1-9]表示参数，参数是指在运行批处理文件时在文件名后加的以空格（或者Tab）分隔的字符串。变量可以从%0到%9，%0表示批处理命令本身，其它参数字符串用%1到%9顺序表示
```
@echo off
IF "%1" == "A" ECHO liu
IF "%2" == "B" ECHO hai
IF "%3" == "C" ECHO song
```
- 在命令行执行的时候如果输入test A B C将会输出liu hai song

变量的初始化：变量可以使用set命令进行变量初始化
> set /A variable-name=value  //如果涉及到数值，则使用/A
```
@echo off 
set message=Hello World 
echo %message%
```
```
//使用数值
@echo off 
SET /A a=5 
SET /A b=10 
SET /A c=%a% + %b% 
echo %c%
```

全局变量与局部变量
在bat中，默认情况下，变量是整个命令提示符会话的全局变量。调用SETLOCAL命令，变量将会被限定在一个局部的范围之内
```
@echo off
set globalvar=5
SETLOCAL
set var = 1234
set /A var=%var%+6
echo %global%
echo %var%
ENDLOCAL
```
- globalvar'是用全局范围定义的，在整个脚本中都是可用的。
- var变量是在局部范围内定义的，因为它被包含在SETLOCAL和ENDLOCAL块之间。 因此，这个变量在执行'ENDLOCAL'语句后就会被销毁。

## 4.字符串操作
```
@echo off 
SET a=Hello 
SET b=World 
SET /A n=5
SET c=%a% %b% //拼接
SET d=%a% and %b% %n%  //字符串插值
echo %c%

输出:
Hello World
Hello and World 5
```
- 截取字符串
```
@echo off
SET str=batsh is easy.it is really easy.
SET str0=%str:~0,20%   //截取字符0-20
SET str1=%str:~2,20%   //截取中间字符2-20
SET str2=%str:easy=%   //从字符串中删除easy
SET str3=%str: =%       //删除所有空格
SET str4=%str:difficult=easy% //将easy替换为difficult
SET str5=%str:~-12%  //从末尾开始读字符
echo %str%
echo %str0%
echo %str1%
echo %str2%
echo %str3%
echo %str4%
echo %str5%

输出：
batsh is easy.it is really easy.
batsh is easy.it is
tsh is easy.it is re
batsh is .it is really .
batshiseasy.itisreallyeasy.
batsh is difficult.it is really difficult.
really easy.
```
## 5.数组
- 创建遍历数组
```
@echo off 
set list=1 2 3 4 
set a[0]=1 
set a[1]=2 
set a[2]=3 
(for %%a in (%list%) do ( 
   echo %%a 
))
echo The first element of the array is %a[0]%    //通过下标获取元素
echo The second element of the array is %a[1]% 
set a[2]=4                                        //修改数组的值
echo The third element of the array is %a[2]%
set a[3]=5                                        //添加元素
echo The third element of the array is %a[3]%
```
- 获取数组长度
```
@echo off 
setlocal enabledelayedexpansion 
set topic[0]=im 
set topic[1]=liu 
set topic[2]=hai 
set topic[3]=song
set topic[4]=learning batsh 
set topic[5]=program 
set "x=0"
for /l %%n in (0,1,5) do ( 
   echo !topic[%%n]! 
)
:SymLoop
if defined topic[%x%] (   //判断变量是否存在
    call echo %%topic[%x%]%%
    set /a "x+=1"
    GOTO :SymLoop
)
echo array length is "%x%"
```
## 6.if语句使用
- if语句的使用
```
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
rem if defined常用于判断变量是否定义
if defined str1 (echo "str1 is defined") else (echo "str1 is not defined")
rem if exist常用于判断文件是否存在
if exist D:\learn\bat\bat.md echo file exist
rem if errorlevel 用于错误判断
xcopy D:\learn\bat\first.bat D:\learn\bat\test\copyfirst.bat
if errorlevel 1 echo copy file fail
if errorlevel 0 echo copy file success
```
## 7.for语句使用
1. for语句的基本形态：
> for %%I in (command1) do command2
> 1. for、in和do是for语句的关键字，它们三个缺一不可；
> 2. %%I是for语句中对形式变量的引用，即使变量l在do后的语句中没有参与语句的执行，也是必须出现的；其中变量I区分大小写，可以换成26个英文字母中的任意一个，但应该避免使用%0-%9
> 3. in之后，do之前的括号不能省略；
> 4. command1表示字符串或变量，command2表示字符串、变量或命令语句；

2. 含开关/L的for语句，可以根据set里面的设置进行循环，从而实现对循环次数的直接控制。其命令格式为：
> for /l %%I in (start,step,end) do command
> 1. start表示开始值，step表示每次递增的值，end表示结束值

3. 含开关/F的for语句具有最强大的功能，它能够对字符串进行操作，也能够对命令的返回值进行操作，还可以访问硬盘上的ASCII码文件，比如txt文档等。其命令格式为：
> for /F ["options"] %%I in (set) do command
> 其中，set为("string"、'command'、file-set)中的一个；options是(eol=c、skip=n、delims=xxx、tokens=x,y,m-n、usebackq)中的一个或多个的组合。各选项的意义参见for /f。一般情况下，使用较多的是skip、tokens、delims三个选项
> 1. delims分隔符，默认是空格，使用delims的时候默认将目标分为n个小节，如this is test file就可以被空格分为4个小节
> 2. tokens用于定位1中的小节，如tokens=3表示获取第3个小节、tokens=2,5获取第2和5小节
> 3. skip=n跳过n行
> 4. eol=x 忽略以x开头的行

4. for /d 参数 查询目录
> FOR /D %%variable IN (set) DO command [command-parameters]
> 1. 这个参数主要用于目录搜索,不会搜索文件。
> 2. 只能搜索指定目录和缺省情况当前目录下的目录名字，不搜索子目录。

5. for /r 参数 遍历搜索指定文件
> FOR /r [[drive:]path] %%variable IN (set) DO command [command-parameters]
> 检查以  [drive:]path  为根的目录树，指向每个目录中的 FOR  语句。如果在  /R  后没有指定目录，则使用当前目录。如果集仅为一个单点(.)字符，则枚举该目录树。如果该值缺省，则遍历当前目录
```
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
```
## 8.函数操作
```
@echo off  
set globalvar=5  
set str=Outer  
rem call function  
rem 函数调用  
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
```

## 9.文件操作
1. 文件创建/写入：都是通过重定向过滤器 > 完成
```
@echo off
echo hello world,this create file test!>D:\learn\bat\test.txt
dir c:\ > D:\learn\bat\c.txt
```
2. 文件附加写入：通过双重重定向 >> 完成
```
@echo off
echo this is file additional write > D:\learn\bat\test.txt
echo +++++++++++++++++++++ >> D:\learn\bat\test.txt
dir c:\ >> D:\learn\bat\test.txt
```
3. 文件读取:借助for循环实现
```
@echo off
FOR /F "tokens=* delims=" %%x in (test.txt) DO echo %%x
```
4. 删除文件：bat提供del命令用于删除文件
> DEL [/P] [/F] [/S] [/Q] [/A[[:]attributes]] names
5. 文件重命名:使用bat脚本提供的ren或rename完成
> RENAME filename renamefile