@echo off 
set list=1 2 3 4 
set a[0]=1 
set a[1]=2 
set a[2]=3 
(for %%a in (%list%) do ( 
   echo %%a 
))
echo The first element of the array is %a[0]%   
echo The second element of the array is %a[1]% 
set a[2]=4
echo The third element of the array is %a[2]%
set a[3]=5
echo The third element of the array is %a[3]%