#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*克服寻找前驱的缺点*/

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node* prev , *next;
    //previous
    
}Node;

/*初始化*/
Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;

}

/*找尾结点*/
Node* Tail(Node *L)
{
    while (L->next!=NULL)
    {
        L = L->next;
    }
    return L;
    
}

/*遍历链表*/
int listNode(Node* head)
{
    Node* L = head;
    while(L != NULL)
    {
        printf("%d",L->data);
        L = L->next;
    }
    printf("\n");
    return 1;
}

/*头插法：逻辑：新节点先指向前驱和后继，之后*/
int insertHead(Node* head ,ElemType e )
{
    Node* p = (Node*)malloc(sizeof(Node*));
    p->data = e;  // W:第一步先赋值给data
    p->prev = head;
    p->next = head->next;

    if(head->next != NULL)
    {
        head->next->prev = p;
    }
    head->next = p;
    return 1;


}
/*尾插法——先找到尾结点，然后进行接入*/
Node* insertTail(Node* tail , ElemType e)
{
    Node *p = (Node*)malloc(sizeof(Node*));
    p->data = e;
    p->next =NULL;
    p->prev = tail;

    tail->next = p;//这里注意，插完了p之后别忘了tail
    return p;

}

/*在指定位置插入节点：
找到要插入位置的前置节点和后置节点*/
Node* insertNode()
{

}

/*释放链表*/
Node* freeList(Node*L)
{
    Node *p = L->next;
    Node* q;

    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next =NULL;
    
}

/*删除节点--也是找到前驱节点*/
int deleteNode(Node*L , int pos)
{
    Node *p = L;
    int i = 0;
    while ( i< pos -1)
    {
        p = p->next;
        i++;
        if(p=NULL)
        {
            return 0;
        }
    }

    if(p == NULL){return 0 ;}


    
}



void main()
{


}