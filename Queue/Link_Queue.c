
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

/*create,这里是带头结点的队列声明方式！！！*/
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

/*入队，带头结点，所以rear指向有值的尾部，
这里和循环队列完全不一样*/
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

/*队列的长度*/
/*这里注意，对于Q而言，计数的时候
front和rear这个变量是不能动的，他们只是被记录的位置
真正的移动要给temp*/
int queueSize(Queue *Q)
{
    int size = 0; //这里必须先初始化赋值，不然后面操控size++的时候会出错

    if (Q->front == Q->rear)
    {
        return size;
    }
    else
    {
        QueueNode* temp = Q->front->next;
        while(temp =! NULL)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
}


int main()
{
    return 0;
}
