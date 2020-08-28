#include<stdio.h>
/*节点类型定义*/
typedef struct Node{
    int data;
    struct Node *next;
} Node,*LinkedList;
/*链表初始化*/
LinkedList listinit()
{
    Node *L;
    L=(Node *)malloc(sizeof(Node));
    if(L==NULL){
        printf("申请分配空间失败");
    }
    L->next=NULL;
}
/*头插法创建链表*/
LinkedList createListHead(){
    Node *L;
    L=(Node*)malloc(sizeof(Node));
    L->next=NULL;

    int x;
    while ((x==scanf("%d",&x))!=EOF)
    {
        Node *p;
        p=(Node*)malloc(sizeof(p));
        p->data=x;
        p->next=L->next;
        L->next=p;
    }
    return L;
}
/*尾插法*/
LinkedList createListTail(){
    Node *L,*r;
    L=(Node *)malloc(sizeof(L));
    L->next=NULL;
    r=L;
    int x;
     while ((x==scanf("%d",&x))!=EOF)
    {
        Node *p;
        p=(Node*)malloc(sizeof(p));
        p->data=x;
        r->next=p;
        r=p;
    }
}