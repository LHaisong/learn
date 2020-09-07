#include<stdio.h>
#include "../sub/sub.h"
#include "../add/add.h"
int main(){
    int a=5,b=4;
    int sub_res=sub(a,b);
    int add_res=add(a,b);
    printf("sub result is：%d\n",sub_res);
    printf("add result is：%d\n",add_res);
    return 0;
}

