#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define INFINITY 32768
#define True 1
#define False 0

typedef char VertexData;
typedef struct {
    int adj;
} ArcNode;

typedef struct {
    VertexData vexs[MAX_VERTEX_NUM];
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
} Graph;

// visited数组
int visited[MAX_VERTEX_NUM];

// 队列结构
typedef struct {
    int data[MAX_VERTEX_NUM];
    int front, rear;
} Queue;

// 队列操作
void InitQueue(Queue *Q) {
    Q->front = Q->rear = 0;
}

int Empty(Queue Q) {
    return Q.front == Q.rear;
}

void EnterQueue(Queue *Q, int x) {
    Q->data[Q->rear++] = x;
}

void DeleteQueue(Queue *Q, int *x) {
    *x = Q->data[Q->front++];
}

//辅助函数
int LocateVertex(Graph *G, VertexData v);
// 输出访问节点
void visit(int v, Graph *G);
// 返回第一个邻接点
int FirstAdjVertex(Graph *G, int v);
// 返回v相对于w的下一个邻接点
int NextAdjVertex(Graph *G, int v, int w);
// 7.8 广度优先搜索图g中v0所在的连通子图
void BreadthFirstSearch(Graph *G, int v0);
// 创建简单图
void CreateSampleGraph(Graph *G);


int main() {
    Graph G;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) visited[i] = False;
    CreateSampleGraph(&G);
    printf("BFS访问顺序：");
    BreadthFirstSearch(&G, 0);  // 从顶点 A 开始
    printf("\n");
    return 0;
}
// 辅助函数
int LocateVertex(Graph *G, VertexData v) {
    for (int i = 0; i < G->vexnum; i++)
        if (G->vexs[i] == v)
            return i;
    return -1;
}

// 输出访问节点
void visit(int v, Graph *G) {
    printf("%c ", G->vexs[v]);
}

// 返回第一个邻接点
int FirstAdjVertex(Graph *G, int v) {
    for (int j = 0; j < G->vexnum; j++) {
        if (G->arcs[v][j].adj != INFINITY)
            return j;
    }
    return -1;
}

// 返回v相对于w的下一个邻接点
int NextAdjVertex(Graph *G, int v, int w) {
    for (int j = w + 1; j < G->vexnum; j++) {
        if (G->arcs[v][j].adj != INFINITY)
            return j;
    }
    return -1;
}

// 7.8 广度优先搜索图g中v0所在的连通子图
void BreadthFirstSearch(Graph *G, int v0) {
    int v, w;
    Queue Q;

    visit(v0, G);
    visited[v0] = True;
    InitQueue(&Q);
    EnterQueue(&Q, v0);
    while (!Empty(Q)) {
        DeleteQueue(&Q, &v);
        w = FirstAdjVertex(G, v);
        while (w != -1) {
            if (!visited[w]) {
                visit(w, G);
                visited[w] = True;
                EnterQueue(&Q, w);
            }
            w = NextAdjVertex(G, v, w);
        }
    }
}

// 创建简单图
void CreateSampleGraph(Graph *G) {
    G->vexnum = 5;
    G->arcnum = 6;
    char vs[] = {'A', 'B', 'C', 'D', 'E'};
    for (int i = 0; i < G->vexnum; i++) {
        G->vexs[i] = vs[i];
    }

    for (int i = 0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adj = INFINITY;

    int edges[6][2] = {
        {0, 1}, {0, 2},
        {1, 2}, {1, 3},
        {2, 4}, {3, 4}
    };

    for (int i = 0; i < G->arcnum; i++) {
        int u = edges[i][0], v = edges[i][1];
        G->arcs[u][v].adj = 1;
        G->arcs[v][u].adj = 1;  // 无向图
    }
}