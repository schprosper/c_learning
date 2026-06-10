/*链表——以一个小方格为一个单位长度*/
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
    struct Node *next;/*存着下一个节点的地址,指向了Node而非仅仅的data*/
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
int insertHead(Node* L,ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;

    return 1;
}

/*尾插法---在最最末尾插，当然，我自己写的真的是太辣鸡了*/
int gabage_insertTail(Node *L,ElemType e){
    Node * curr = NULL;//current 当前节点
    Node * final = NULL;//存储最后的一个位置
    Node * newNode = NULL;
    curr = L->next;
    while (curr !=NULL)
    {
        final = curr;
        curr = curr->next;
    }
    //结束之后的curr是null，所以你需要一个承接最后可用地址的变量。
    newNode = (Node*)malloc(sizeof(Node));

    newNode->data = e;
    final->next= newNode; //这里曾经接反了
    return 1;
    
}
/*尾插法----直接在While里面进行检测（这里无论传入的是不是尾节点都可以！*/
/*保存是一个逻辑，检验是一个逻辑*/
/*经验--一旦你发现，你需要用【a-1】，那么就吧计算【a】的过程给放到循环里面*/
int insertTail(Node *L, ElemType e) {
    Node *curr = L;//当前节点
    Node *newNode = NULL;

    while (curr->next != NULL)
    //直接同时处理了空表！！！

    {
        curr = curr->next;
    }

    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        //给予内存错误。
        return 0;
    }

    newNode->data = e;
    newNode->next = NULL;
    curr->next = newNode;

    return 1;
}

/*分开来的尾插法*/
/*RE——先赋值给tail = L,保证能够处理空表*/
Node* get_tail(Node *L){
    //Node* tail = NULL;
    Node* tail = L;
    while(L->next != NULL){
        L = L->next;
        tail  = L->next;
    }

    return tail;

}

/*遍历链表*/
void listNode(Node *head){
    Node *p = NULL;
    p = head->next;
    
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }

    printf("\n");


}
 
/*指定位置插入数据*/
/*首先你得想想是插入到第几个*/ 

int main(){
    Node *list = initList();
    insertHead(list,10);
    insertHead(list,20);
    insertHead(list,30);
    listNode(list);//输出是30 20 10——头插法，的顺序和排列的顺序是相反的

    return 1;
}
