#include<stdio.h>

int callback_1(int a)
{
    printf("function enter callback_1,x=%d\n",a);
}
int callback_2(int b)
{
    printf("function enter callback_2,x=%d\n",b);
}
int callback_3(int c)
{
    printf("function enter callback_3,x=%d\n",c);
}
int handle(int x,int (*pCallback)(int))
{
    printf("handle function x=%d\n",x);
    pCallback(x);
}
int main()
{
    int a=1,b=2,c=3;
    handle(a,callback_1);
    handle(b,callback_2);
    handle(c,callback_3);    
    return 0;
}