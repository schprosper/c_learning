/*只是遵循栈的逻辑的链表——也就是头插法、
删除头结点的下一个
看头结点的next为空值
获取栈顶值？head->next*/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType_Stack;

typedef struct Stack
{
    ElemType_Stack data;
    struct Stack* next;
}Stack;

/*空栈*/
int isEmpty(Stack *s)
{
    if (s->next == NULL)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}


/*初始化*/
Stack* initStack()
{
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->data = 0;
    S->next = NULL;

    return S;
}

/*进栈*/
int push(Stack* S, ElemType_Stack e)
{
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}

int pop(Stack* S, ElemType_Stack *e)
{
    Stack * temp = S->next;
    *e = temp->data;
    S->next = temp->next;
    free(temp);
    return 1 ;
}

int main()
{
    return 0;
}


