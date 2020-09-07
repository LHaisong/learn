#include<stdio.h>
int main(int argc,char *argv[],char *envp[])
{
	int i = 0;
	for (i = 0; i < argc; i++)
	{
		printf("%s,%d\n", argv[i],i);
	}
	return 0;
}