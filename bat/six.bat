@echo off
::set message=Hello World 
::echo %message%
::SET /A a=5 
::SET /A b=10 
::SET /A c=%a% + %b% 
::echo %c%
::set globalvar=5
::SETLOCAL
::set var = 14
::set /A var = %var% + 9
::echo %var%
::echo %global%
::ENDLOCAL
SET a=Hello
SET b=World
SET /A n=5
SET c=%a% %b%
SET d=%a% and %b% %n%
echo %c%
echo %d%