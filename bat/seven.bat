@echo off
SET str=batsh is easy.it is really easy.
SET str0=%str:~0,20%
SET str1=%str:~2,20%
SET str2=%str:easy=%
SET str3=%str: =%
SET str4=%str:easy=difficult%
SET str5=%str:~-12%
echo %str%
echo %str0%
echo %str1%
echo %str2%
echo %str3%
echo %str4%
echo %str5%