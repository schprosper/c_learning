#include <stdio.h>

/*栈的顺序结构*/
#define MAXSIZE 100
typedef int ElemType;

/*数据结构的定义*/
/*包含数组的大大一块*/
typedef struct
{
    ElemType data[MAXSIZE];
    int top;

}Stack;


/*初始化:top为-1*/
void initStack(Stack *L)
{
    L->top = -1;
}


/*判断栈是否为空*/
void isEmpty(Stack *L)
{
    if (L->top == -1)
    {
        printf("Empty\n");
        return;
    }
    else 
    {
        printf("Not Empty\n");
        return;
    }
}

/*进站压栈，让top当下标来用*/
/*Stack* push(Stack*s , ElemType e)
{
    (s->top)++;
    s->data[s->top] = e;
    return s;
}*/

/*我们传入指针进行的操作，根本不需要你再返回什么东西
只需要知道是否成功即可*/
int push(Stack*s , ElemType e)
{
    //进去，那么要求他不满！
    if(s->top == MAXSIZE -1)
    {
        printf("Maxed!!\n");
        return 0;
    }

    (s->top)++;
    s->data[s->top] = e;
    return 1;
}

/*出栈：先把要删除的数据先给出去*/
int pop(Stack* s, ElemType *e)
{
    if(s->top == -1)
    {
        printf("Empty Already");
        return 0;
    }

    *e = s->data[s->top];
    (s->top)--;
    return 1;
}


int getTop(Stack*s , ElemType*e)
{
    *e = s->data[s->top];
    return 1;
}




int main(int argc, char const *argv[])
{
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    ElemType e;
    pop(&s, &e);
    printf("%d\n", e);
    getTop(&s, &e);
    printf("%d\n", e);

    return 0;
}








