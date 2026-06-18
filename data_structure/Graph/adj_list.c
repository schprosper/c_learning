#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100 //最大顶点数

/*VertexNode 定义：V0、V1、V2、V3 这一列
EdgeNode   定义：V0 后面的 1 -> 2 -> 3 这些链表结点
AdjList[]  定义：整个数组下标 [0] [1] [2] [3]*/

//结点 边表结点结构体（V0123后面接的尾巴）-- 一个链表
typedef struct EdgeNode
{
    int aijvex;  //邻接点在顶点数组中的下标
    struct EdgeNode *next;
}EdgeNode;

//顶点表结点结构体


typedef struct 
{

}GraphAdjList;
