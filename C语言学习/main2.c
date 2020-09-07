#include<stdio.h>
#include<stdlib.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main(int argc,char *argv[],char *envp[])
{
	int x = 0;
	int y = 0;
	int ret = 0;
	if (argc != 4)
	{
		printf("请检查参数个数");
		return 0;
	}
	//判断-a -s -m -d中的哪一种
	x = atoi(argv[2]);
	y = atoi(argv[3]);
	switch (*(argv[1] + 1))
	{
	case 'a':
		//Add(*(argv[2]),*(argv[3]));错误，因为char* 类型
		//atoi()函数 把字符串转换成整数   解决方案ex7右击属性 命令参数里加入-a 123 321
		ret = Add(x, y);
		break;
	case 's':
		ret = Sub(x, y);
		break;
	case 'm':
		ret = Mul(x, y);
		break;
	case 'd':
		ret = Div(x, y);
		break;
	default:
		printf("参数有误\n");
		break;
	}
	printf("%d\n", ret);
	return 0;
}