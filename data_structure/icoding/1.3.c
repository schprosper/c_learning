/*链表 删除范围内结点

已知线性表中的元素（整数）以值递增有序排列，
并以单链表作存储结构。
试写一高效算法，删除表中所有大于mink且小于maxk的元素
（若表中存在这样的元素），分析你的算法的时间复杂度。

链表结点定义如下：
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;
函数原型如下：
void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk)

其中L指向链表的头结点。*/

// 是递增的！


#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk) {

    LinkList pre = L;
    LinkList p,q;

    while (pre->next->data <= mink)
    {
        pre = pre->next;
    }

    p = pre->next;

    while(p->data <maxk)
    {
        q = p;
        p = p->next;
        free(q);
    }

    pre->next =p;
    

}

/*
顺序表 数据调整

已知顺序表L中的数据元素类型为int。
设计算法将其调整为左右两部分，
左边的元素（即排在前面的）均为奇数，右边所有元素（即排在后面的）均为偶数，
并要求算法的时间复杂度为O(n),空间复杂度为O（1）。

函数原型如下：
void odd_even(SeqList *L);

相关定义如下：
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;*/

struct _seqlist{
    ElemType elem[100];
    int last;
};
typedef struct _seqlist SeqList;


/*第四题——顺序表左右指针调整*/
void odd_even(SeqList *L) {
    int i = 0;
    int j = L->last;
    int temp;

    while (i < j) {
        if (L->elem[i] % 2 != 0) {
            // 左边已经是奇数，位置正确
            i++;
        } else if (L->elem[j] % 2 == 0) {
            // 右边已经是偶数，位置正确
            j--;
        } else {
            // 左边是偶数，右边是奇数，交换
            temp = L->elem[i];
            L->elem[i] = L->elem[j];
            L->elem[j] = temp;

            i++;
            j--;
        }
    }
}

void odd_even(SeqList *L)
{
    int i =0;
    int j = L->last;
    int temp;
    
    while ( i<j)
    {
        if(L->elem[i]%2 != 0)
        {
            i++;
        }
        else if (L->elem[j]%2 == 0)
        {
            j--;
        }
        else
        {
            temp = L->elem[i];
            L->elem[i] = L->elem[j];
            L->elem[j] = temp;

            i++;
            j--;
        }
    }
    
}

void odd_even(SeqList *L)
{
    int i = 0; 
    int j = L->last;
    int temp ;

    while(i<j)
    {
        if(L->elem[i]%2 == 0)
        {
            i++;
        }
        else if(L->elem[j]%2 != 0)
        {
            j --;
        }
        else
        {
            temp = L->elem[i];
            L->elem[i]=L->elem[j];
            L->elem[j] = temp;

            i++;
            j--;
        }
    }
}



/*顺序表 删除重复

编写算法，在一非递减的顺序表L中，
删除所有值相等的多余元素。要求时间复杂度为O(n)，空间复杂度为O(1)。

函数原型如下：
void del_dupnum(SeqList *L)

相关定义如下：
*/
struct _seqlist{
    ElemType elem[100];
    int last;
};
typedef struct _seqlist SeqList;

/*删除重复*/
void del_dupnum(SeqList *L) {
    int write;
    int read;

    if (L->last <= 0) {
        return;
    }

    write = 0;
    read = 1;

    while (read <= L->last) {
        if (L->elem[read] != L->elem[write]) {
            write++;
            L->elem[write] = L->elem[read];
        }
        read++;
    }

    L->last = write; //忘记有这个
}

void del_dupnum(SeqList *L)
{
    int write =0;
    int read = 1;

    if(read > L->last)
    {
        return;
    }

    while(read <= L->last) //while(read > L->last)
    //While里面是什么时候进行，什么时候不进行好判，但要转个弯。
    {
        if(L->elem[write]!=L->elem[read])
        {
            write++;
            L->elem[write] = L->elem[read];
        }
        read ++;
    }

    L->last = write;
}

/*
顺序表 删除指定范围

设计一个高效的算法，从顺序表L中删除所有值介于x和y之间(包括x和y)的所有元素
（假设y>=x），要求时间复杂度为O(n)，空间复杂度为O(1)。

函数原型如下：
void del_x2y(SeqList *L, ElemType x, ElemType y);

相关定义如下：
*/

/*删除指定范围——数值 、 没有顺序*/
void del_x2y(SeqList *L, ElemType x, ElemType y) {
    int read = 0;
    int write = 0;

    while (read <= L->last) {
        if (L->elem[read] < x || L->elem[read] > y) {
            L->elem[write] = L->elem[read];
            write++;
        }
        read++;
    }

    L->last = write - 1;
}
//变式：保留之间的元素
void del_x2y(SeqList *L, ElemType x, ElemType y) 
{
    int write =0;
    int read = 0;

    while(read <= L->last)
    {
        if(L->elem[read] >= x && L->elem[read]<=y)
        {
            L->elem[write] = L->elem[read];
            write ++;
        }
        read++;
    }
    L->last = write -1;
}










































































































































