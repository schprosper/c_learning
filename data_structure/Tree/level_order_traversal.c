/*层序遍历*/
#include <stdio.h>
#include <stdlib.h>
//===================队列定义一下============
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

/*入队*/
void equeue(Queue*Q , ElemType *e){};

/*出队——知道是哪个队列，并且记录出队元素*/
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


// ================TreeNode======================

typedef char ElemType;

typedef struct TreeNode
{
    ElemType data ;
    struct TreeNode* lchild ;
    struct TreeNode* rchild ;

}TreeNode;

//这里传入的其实是指向树根的指针。
typedef TreeNode* BiTree;
//===================== 求高度=====================

/*层序遍历：
知道这一层有几个元素，依次清除元素
当这一层为被清除空的时候，这一层完毕（说明有这一层）
让depth++，之后进去下一层，记录下一层有几个元素。
通过每层的元素匹配来做的遍历

这里的队列，存储的是树节点的坐标！！把坐标给他拿出去了！！
用到了，队列，队列逻辑，但换了data类型
*/

/*让树的节点（通过指针、地址来代表）进队
——知道A层一共m个节点，并且记录
——在遍历A层的时候，会发现孩子节点，用队的逻辑（后进后处理），他们入队但后处理
——A层m个节点都出去了，深度加一
——统计下一层的节点数。*/
int maxDepth(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    int depth = 0;
    Queue * Q = initQueue();
    equeue(Q , root) ;
    //你这里要对树进行操作，那么就需要让树（的地址）入队
    while (!isEmpty(Q))
    {
        int count = QueueSize(Q);
        
        while (count != 0)
        {
            TreeNode *curr;
            dequeue(Q ,&curr);
            if(curr->lchild != NULL)
            {
                equeue(Q,curr->lchild);
            }
            if (curr->rchild!=NULL)
            {
                equeue(Q,curr->rchild);
            }
            count --;
        }
        depth ++;
        
    }
    return depth;
    
    

    
}











