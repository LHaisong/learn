#include<stdio.h>
#include<string.h>
#include <stdlib.h>
/*指针作为函数参数*/
void swap(int *p1,int *p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;
}
/*把指针作为返回值*/
char *compare(char *pstr1,char *pstr2)
{
    if(strlen(pstr1)>strlen(pstr2)){
        return pstr1;
    }
    return pstr2;
}
int main()
{
    /**
    char str[]="this is a string";
    char *pstr=str;
    printf("\nstr 输出:");
    for(int i=0;i<strlen(str);i++)
    {
        printf("%c",pstr[i]);
    }
    printf("\nstr 输出:");
    for(int i=0;i<strlen(str);i++)
    {
        printf("%c",*(pstr+i));
    }
     printf("\nstr 输出:");
    for(int i=0;i<strlen(str);i++)
    {
        printf("%c",*pstr++);
    }
    **/
    int a=10,b=20;
    char *pstr1="this is a string";
    char *pstr2="this is a string.";
    swap(&a,&b);
    printf("after swap a=%d b=%d.\n",a,b);
    void (*pSwap)(int*,int*)=swap;
    pSwap(&a,&b);
    printf("after pSwap a=%d b=%d.\n",a,b);
    printf("long string is:%s",compare(pstr1,pstr2));
    return 0;
}