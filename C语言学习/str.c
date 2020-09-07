#include<stdio.h>
#include<string.h>
#define PATH "TEST"
int main()
{
    char dst[]="/media/ftp/upload/";
	char s1[]=PATH;
	
	strcat(s1,dst);
	char *file_dst=s1;
    printf("file name is:%s\n",file_dst);
    return 0;
}