#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 10
#define INFINITY 32768
#define True 1
#define False 0
#define Error -1
#define Ok 1

typedef enum { DG, DN, UDG, UDN } GraphKind;  // 图的种类
typedef char VertexData;
GraphKind kind = DN;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode * nextarc;

}ArcNode;

typedef struct VertexNode{
    VertexData data;
    ArcNode* firstarc;
}VertexNode;

typedef struct {
    VertexNode Vertex[MAX_VERTEX_NUM];
    int vexunm ,arcnum;
    GraphKind kind;
}AdjList;

//===============十字链表==============

typedef struct ArcNode
{
    int headvex,tailvex; 
    //头尾编号(之后内存空间申请，以结构体为单位，不要担心)

    struct ArcNode *hlink , *tlink;
}ArcNode;

typedef struct VertexNode
{
    char VertexData;
    ArcNode *firstin ,*firstout; // in out 一进一出度；
}VertexNode;

typedef struct Orthlist
{
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
}Orthlist;
