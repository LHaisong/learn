#include<stdio.h>

int main()
{
    char str[20];
    printf("请输入:");
    fgets(str,19,stdin);//从控制台获取19个字符到str中
    fputs(str,stdout);
    return 0;
}