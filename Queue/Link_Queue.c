#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct QueueNode
{
    ElemType data;
    struct QueueNode* next;
}QueueNode;
typedef struct 
{
    QueueNode* front;
    QueueNode* rear;
}Queue;

/*create*/
Queue* initQueue()
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    Queue* Q = (Queue*)malloc(sizeof(Queue));

    node->data = 0;
    node->next= NULL;

    Q->front = node;
    Q->rear =  node;
    return Q;
}

/*判断是否为空*/
int isEmpty(Queue* Q)
{
    if(Q->front == Q->rear)
    {
        printf("Empty!\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

/*入队*/
void equeue(Queue *Q,ElemType e)
{
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->data = e;
    node->next =NULL;
    
    Q->rear->next = node;
    Q->rear =node;

}

/*出队*/
void dequeue(Queue *Q, ElemType *e)
{
    QueueNode* temp = Q->front->next; // 那么temp应该是链表类型的变量
    *e = temp->data;
    Q->front->next = temp->next;
    if(Q->rear == temp)// 三种情况——空队 、 剩了一个 、剩了大于等于一个
    {
        Q->front = Q->rear;
    }
    free(temp);
}

int main()
{
    return 0;
}
