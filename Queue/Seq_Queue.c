#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct 
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

/*init*/
void initQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear =0;
}

/*出队*/
ElemType deQueue(Queue* Q)
{
    if(Q->front == Q->rear)
    {
        printf("Empty!\n");
        return 0;
    }
    else
    {
    ElemType e = Q->data[Q->front];
    Q->front++;

    return e;
    }
}

/*判断队列是否为空 ， 如果不空那么前移*/
int queueFull(Queue* Q)
{
    if(Q->front >0)
    {
        int step = Q->front;
        for(int i = Q->front; i <= Q->rear ;i++)
        {
            Q->data[i - step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else
    {
        printf("completely Full!!!");
        return 0;
    }
    
}

/*有了上面判断为空的铺垫，现在可以入队了*/
int qeueue(Queue* Q,ElemType e)
{
    //先判断是否是到顶了的那种满了
    if(Q->rear >= MAXSIZE -1)
    {
        if(!queueFull(Q))
        {
            return 0;
        }
    
    }

    Q->data[Q->rear] = e;
    Q->rear++;
    return 1;

}

/*获取队头*/
int getHead(Queue *Q,ElemType *e)
{
    if(Q->front == Q->rear)
    {
        printf("empty!!!\n");
        return 0;
    }

    *e = Q->data[Q->front];
    return 1;
}

int main()
{

}
 