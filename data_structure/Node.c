//开始链表
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
/*==================定义==================*/
/*单链表*/
typedef int ElemType;

/*先对单个节点进行定义*/
typedef struct Node
{
    ElemType data;
    struct Node *next;/*存着下一个节点的地址*/
}Node,* LinkList;/*LinkList 是“指向 Node 的指针类型”*/

/*==============函数==========================*/
/*单链表初始化——直接在堆内存里面玩*/
Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head ->data = 0;
    head ->next = NULL;
    return head;

}

/*头插法——每次插入在头节点后面去插入数据，屁股插入*/
void insertHead(Node* L,ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}


int main(){
    Node *list = initList();
    insertHead(list,10);
    insertHead(list,20);
    return 1;
}
