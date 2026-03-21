//开始链表
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*单链表*/
/*用typeof 原类型 新名字*/
typedef struct Node
{
    int data;
    struct Node *next;/*存着下一个节点的地址。*/
}Node,* LinkList;/*LinkList 是“指向 Node 的指针类型”*/

/*
typedef struct Node Node;
typedef struct Node* LinkList;
*/

LinkList L;
/**/

void init_linklist(LinkList* L){
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;
}


