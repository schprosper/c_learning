#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20

typedef struct ArcNode {
    int adjvex;                  // 邻接点在顶点数组中的下标
    int weight;                  // 权值（本例用不上）
    struct ArcNode *nextarc;    // 指向下一条边
} ArcNode;

typedef struct VertexNode {
    char data;                   // 顶点名称（可选）
    ArcNode *firstarc;           // 指向第一条边
} VertexNode;

typedef struct {
    VertexNode vertexes[MAX_VERTEX_NUM]; // 顶点数组
    int vexnum;                          // 顶点数
    int arcnum;                          // 边数
} Graph;


//7.12 求入度算法
void FindID(Graph G, int indegree[MAX_VERTEX_NUM]) ;
// 创建一个简单有向图（邻接表）
void CreateSampleGraph(Graph *G);


int main() {
    Graph G;
    int indegree[MAX_VERTEX_NUM];

    CreateSampleGraph(&G);
    FindID(G, indegree);

    printf("顶点入度如下：\n");
    for (int i = 0; i < G.vexnum; i++) {
        printf("顶点 %c 入度: %d\n", G.vertexes[i].data, indegree[i]);
    }

    return 0;
}

//7.12 求入度算法
void FindID(Graph G, int indegree[MAX_VERTEX_NUM]) {
    int i;
    ArcNode *p;
    for (i = 0; i < G.vexnum; i++) {
        indegree[i] = 0;  // 初始化入度为0
    }
    for (i = 0; i < G.vexnum; i++) {
        p = G.vertexes[i].firstarc;
        while (p != NULL) {
            indegree[p->adjvex]++;  // 被指向的点入度 +1
            p = p->nextarc;
        }
    }
}

// 创建一个简单有向图（邻接表）
void CreateSampleGraph(Graph *G) {
    int i;
    G->vexnum = 5;
    G->arcnum = 5;

    for (i = 0; i < G->vexnum; i++) {
        G->vertexes[i].data = 'A' + i;  // 顶点名 A B C D E
        G->vertexes[i].firstarc = NULL;
    }

    // 添加边 A→B, A→C, B→D, C→D, D→E
    ArcNode *p;

    // A → B
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 1; p->weight = 0;
    p->nextarc = G->vertexes[0].firstarc;
    G->vertexes[0].firstarc = p;

    // A → C
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 2; p->weight = 0;
    p->nextarc = G->vertexes[0].firstarc;
    G->vertexes[0].firstarc = p;

    // B → D
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 3; p->weight = 0;
    p->nextarc = G->vertexes[1].firstarc;
    G->vertexes[1].firstarc = p;

    // C → D
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 3; p->weight = 0;
    p->nextarc = G->vertexes[2].firstarc;
    G->vertexes[2].firstarc = p;

    // D → E
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 4; p->weight = 0;
    p->nextarc = G->vertexes[3].firstarc;
    G->vertexes[3].firstarc = p;
}