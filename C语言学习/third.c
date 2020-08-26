/*计算1！+2！+3！+.....+10！*/
# include<stdio.h>
# include<string.h>
/*函数声明，提前告诉编译器需要使用这个函数，参数可省略*/
int fac(int);
int sum(int);
int strchar(char* str,char c);
int fac(int m)
{
    int res=1;
    for(int i=1;i<=m;i++){
        res=res*i;
    }
    return res;
}
int sum(int n)
{
    int res=0;
    for(int i=1;i<n;i++){
        res+=fac(i);
    }
    return res;
}
int strchar(char* str,char c)
{
    for(int i=0;i<strlen(str);i++){
        if(str[i]==c){
            return 1;
        }
    }
    return 0;
}

/*函数先定义后使用，必须定义在main()之前*/
int main(){
    char c='c';
    char str[]="c language";
    printf("1！+2！+3！+.....+10=%ld\n",sum(10));
    if(strchar(str,c)==1){
        printf("字符串%s中存在%c\n",str,c);
    }else
    {
        printf("字符串%s中不存在%c\n",str,c);
    }
    
    return 0;
}