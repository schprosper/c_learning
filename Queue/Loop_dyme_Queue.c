#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct 
{
    ElemType *data;
    int front;
    int rear;
}Queue;

/*init,这里应该叫create，因为他会返回一个Queue
然后 我觉得可以 (Q->rear + 1) % MAXSIZE == Q->front
把这个直接先写一遍....，核心公式是 +1并且与MAX取余*/

Queue* initQueue()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    ElemType* data = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    Q->front = 0;
    Q->rear =MAXSIZE -1;
    return Q;
}

/*出队*/
int dequeue(Queue* Q, ElemType *e)
{
    if(Q->rear == Q->front)
    {
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front +1) % MAXSIZE;
    return 1;
}

/*入队*/
int equeue(Queue* Q,ElemType* e)
{
    if ((Q->front +1)% MAXSIZE == Q->front)
    {
        printf("Full!\n");
        return 0;
    }
    Q->data[Q->rear] = *e;
    Q->rear = (Q->rear +1) % MAXSIZE;
    return 1;
}
int main()
{
    return 0;
}