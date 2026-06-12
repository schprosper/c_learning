#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

/*栈的动态内存分配初始化*/
typedef struct 
{
    ElemType *data;
    int top;
}Stack;

/*init*/
Stack* initStack()
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    //`malloc` 的作用是：**在运行时申请一块内存空间，并返回这块空间的首地址**
    ElemType* data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1
    return s;

}


int main()
{
    Stack *s = initStack();
    return 1;
}