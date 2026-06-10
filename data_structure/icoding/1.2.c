/*链表 倒数查找

已知一个带有表头结点的单链表, 假设链表只给出了头指针L。
在不改变链表的前提下，请设计一个尽可能高效的算法，
查找链表中倒数第k个位置上的结点（k为正整数）。*/

/*思路————如何确定是最后第k个指针？
框出一个位置来！*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

int lnk_search(LinkList L, int k, ElemType* p_ele)
{
    Node* fast = NULL;
    Node* slow = NULL;

    int i ;
    
    for( i =0 ; i<k&&fast !=NULL; i++){
        fast = fast->next;
    }

    if(i<k){return 0;}

    while(fast !=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    *p_ele = slow->data;




    return 1;
}