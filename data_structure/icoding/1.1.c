#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_merge(LinkList A, LinkList B, LinkList C) {

    Node* pa = A->next;
    Node* pb = B->next;
    //Node* pc = C->next;
    Node* pc = C;  //  C本身指向C链表的头结点？？？？？
    while(pa !=NULL &&pb !=NULL )
    /*没必要data，新链表,要的是链接连起来就行了*/
    {
        pc->next = pa;  // 让 pc 这个指针变量，指向 pa 指向的那个结点。
        pc = pc->next; // 这两句没问题 
        pa = pa->next; //

        pc->next = pb;
        pc = pc->next;
        pb = pb->next;
    }

    while ( pa = NULL)
    {
        pc->next = pb;
        pc = pc->next;
        pb = pb->next;
    }

    while(pb = NULL)
    {
        pc->next = pa;
        pc = pc->next;
        pa = pa->next;
    }
}

