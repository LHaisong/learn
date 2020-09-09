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
if defined topic[%x%] (  
    call echo %%topic[%x%]%%
    set /a "x+=1"
    GOTO :SymLoop
)
echo array length is "%x%"

