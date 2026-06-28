/*
栈 后缀表达式计算

请使用已定义好的栈完成后缀表达式计算：
(1)如果是操作数，直接入栈

(2)如果是操作符op，连续出栈两次，
得到操作数x 和 y,计算 x op y，并将结果入栈。

后缀表达式示例如下：
9  3  1  -  3  *  +  10  2  /  +
13  445  +  51  /  6  -
操作数、操作符之间由空格隔开，操作符有 +，-，*, /, %共 5 种符号，所有操作数都为整型。

栈的定义如下：

#define Stack_Size 50
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S);
其中，栈初始化的实现为：

void init_stack(Stack *S){
    S->top = -1;
}
需要完成的函数定义为：int compute_reverse_polish_notation(char *str);

函数接收一个字符指针，该指针指向一个字符串形式的后缀表达式，函数返回该表达式的计算结果。*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef int ElemType;

#define Stack_Size 50
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x); //入栈
bool pop(Stack* S, ElemType *x); // 出栈
void init_stack(Stack *S);
void init_stack(Stack *S){
    S->top = -1;
}

#include <stdio.h>
#include <stdlib.h>


/*直接默写吧*/
int compute_reverse_polish_notation(char *str)
{
    Stack s;
    init_stack(&s);

    int len  = (int)strlen(str) ;//这里传入参数不会,
    //传入str 一个字符串指针
    int i =0;
    while(i< len)
    {
        if(str[i] == ' ')
        {
            i++;
        }
        else if(str[i] >= '0'&& str[i]<='9')
        {
            int num = 0;
            while(i<len && str[i] >= '0'&& str[i]<='9') //这里应该是While
            {
                num = num*10 + (str[i] - '0');
                i++;//这里也忘记了
            }
            push(&s,num);
        }
        else
        {
            ElemType y ;
            ElemType x ;
            pop(&s,&y);
            pop(&s,&x);
            switch(str[i])
            {
                case '+':
                push(&s,x+y);
                break;

                case '-':
                push(&s,x-y);
                break;
                
                case '*':
                push(&s,x*y);
                break;
                case '/':
                push(&s,x/y);
                break;
                case '%':
                push(&s,x%y);
                break;
            }
            i++; //这里也忘记了
        }

    }
    ElemType result;
    pop(&s,&result);
    return result;
}


/*
队列 循环链表表示队列

假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），请完成下列任务：


1: 队列初始化，成功返回真，否则返回假： bool init_queue(LinkQueue *LQ);

2: 入队列，成功返回真，否则返回假： bool enter_queue(LinkQueue *LQ, ElemType x);

3: 出队列，成功返回真，且*x为出队的值，否则返回假 bool leave_queue(LinkQueue *LQ, ElemType *x);

相关定义如下：

typedef struct _QueueNode {
    ElemType data;          // 数据域
    struct _QueueNode *next;      // 指针域
}LinkQueueNode, *LinkQueue;*/

/* 循环： 必须能成环。 队尾指针位置不变性
需要二级指针—— 因为返回bool，函数的传值复制。 
没有头结点，用尾结点表示头结点！*/

typedef struct _QueueNode {
    ElemType data;          // 数据域
    struct _QueueNode *next;      // 指针域
}LinkQueueNode, *LinkQueue;

#include <stdio.h>
#include <stdlib.h>

// 队列初始化
bool init_queue(LinkQueue *LQ) {
    LinkQueueNode *head;

    head = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (head == NULL) {
        return false;
    }

    head->next = head;   // 空队列：头结点指向自己
    *LQ = head;          // 空队列时，尾指针也指向头结点

    return true;
}

// 入队列
bool enter_queue(LinkQueue *LQ, ElemType x) {
    LinkQueueNode *s;

    s = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
    if (s == NULL) {
        return false;
    }

    s->data = x;

    // *LQ 是队尾结点
    // (*LQ)->next 是头结点
    s->next = (*LQ)->next;  // 新结点指向头结点
    (*LQ)->next = s;        // 原队尾指向新结点
    *LQ = s;                // 新结点成为队尾

    return true;
}

// 出队列
bool leave_queue(LinkQueue *LQ, ElemType *x) {
    LinkQueueNode *head;
    LinkQueueNode *p;

    // 空队列判断：尾指针的 next 还是自己，说明只有头结点 不是指NULL
    if ((*LQ)->next == *LQ) {
        return false;
    }

    head = (*LQ)->next;  // 头结点
    p = head->next;      // 队头元素结点

    *x = p->data;        // 取出队头元素

    head->next = p->next; // 删除队头结点

    // 如果删除的是最后一个数据结点
    if (p == *LQ) {
        *LQ = head;       // 队尾重新指向头结点
    }

    free(p);

    return true;
}



bool init_queue(LinkQueue *LQ)

{
    LinkQueueNode* head = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if(head =NULL)
    {
        return false;
    }
    
    head->next =head;
    *LQ = head;
    return true;

}

bool enter_queue(LinkQueue *LQ, ElemType x)
{
    LinkQueueNode *s = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    //这里差点写成 LinkQueueNode s了。但是为什么不是？？
    s->data = x;

    s->next = (*LQ)->next;
    (*LQ)->next  = s;
    (*LQ) = s;

    return true;
}

bool leave_queue(LinkQueue *LQ, ElemType *x)
{
    LinkQueueNode* head;
    LinkQueueNode* delet;
    head = (*LQ)->next;
    if((*LQ)== head)
    {
        return NULL;
    }

    delet = head->next;
    head->next = delet->next;
    if(delet == (*LQ))
    {
        (*LQ) = head;
    }

    free(delet);
    return true;

}