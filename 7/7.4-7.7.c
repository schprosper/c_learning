
#include <malloc.h>
#include <stdio.h>

#define MAXN 20
int visited[MAXN];

// 返回顶点 v 的第一个邻接点编号
int FirstAdjVertex(int g[][MAXN], int n, int v);
// 返回 v 相对于 w 的下一个邻接点
int NextAdjVertex(int g[][MAXN], int n, int v, int w);
// 深度优先搜索1
void DepthFirstSearch1(int g[][MAXN], int n, int v0);
//7.4 深度优先遍历v0所在的连通子图
void TraverseGraph1(int g[][MAXN], int n);
// 深度优先搜索2
void DepthFirstSearch2(int g[][MAXN], int n, int v0);
//7.5 采用邻接矩阵的DepthFirstSearch
void TraverseGraph2(int g[][MAXN], int n);



typedef struct ArcNode {
    int adjvex;
    struct ArcNode* nextarc;
} ArcNode;

typedef struct {
    ArcNode* firstarc;
} VNode;

typedef struct {
    int vexnum;
    VNode vertex[MAXN];
} AdjList;

typedef struct {
    int data[MAXN];
    int top;
} Stack;

void InitStack(Stack* s) { s->top = -1; }
int Empty(Stack* s) { return s->top == -1; }
void Push(Stack* s, int x) { s->data[++s->top] = x; }
int Pop(Stack* s) { return s->data[s->top--]; }

// 深度优先搜索3
void DepthFirstSearch3(AdjList g, int v0);
//7.6 采用邻接表的DepthFirstSearch
void TraverseGraph3(AdjList g);
// 深度优先搜索4（非递归）
void DepthFirstSearch4(int g[][MAXN], int n, int v0);
//7.7 非递归形式的DepthFirstSearch
void TraverseGraph4(int g[][MAXN], int n);
// 构建用于测试的邻接矩阵图
void BuildMatrixSample(int g[][MAXN], int* n);
// 构建用于测试的邻接表图
void BuildListSample(AdjList* g);



int main() {
    int g[MAXN][MAXN], n;
    AdjList listg;

    printf("=== 7.4 深度优先遍历v0所在的连通子图 ===\n");
    BuildMatrixSample(g, &n);
    TraverseGraph1(g, n);

    printf("\n=== 7.5 采用邻接矩阵的DepthFirstSearch ===\n");
    BuildMatrixSample(g, &n);
    TraverseGraph2(g, n);

    printf("\n=== 7.6 采用邻接表的DepthFirstSearch ===\n");
    BuildListSample(&listg);
    TraverseGraph3(listg);

    printf("\n=== 7.7 非递归形式的DepthFirstSearch ===\n");
    BuildMatrixSample(g, &n);
    TraverseGraph4(g, n);

    return 0;
}



// 返回顶点 v 的第一个邻接点编号
int FirstAdjVertex(int g[][MAXN], int n, int v) {
    for (int i = 0; i < n; i++)
        if (g[v][i] == 1) return i;
    return -1;
}
// 返回 v 相对于 w 的下一个邻接点
int NextAdjVertex(int g[][MAXN], int n, int v, int w) {
    for (int i = w + 1; i < n; i++)
        if (g[v][i] == 1) return i;
    return -1;
}

// 深度优先搜索1
void DepthFirstSearch1(int g[][MAXN], int n, int v0) {
    printf("Visited %d\n", v0);
    visited[v0] = 1;
    int w = FirstAdjVertex(g, n, v0);
    while (w != -1) {
        if (!visited[w])
            DepthFirstSearch1(g, n, w);
        w = NextAdjVertex(g, n, v0, w);
    }
}

//7.4 深度优先遍历v0所在的连通子图
void TraverseGraph1(int g[][MAXN], int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DepthFirstSearch1(g, n, i);
}
// 深度优先搜索2
void DepthFirstSearch2(int g[][MAXN], int n, int v0) {
    printf("Visited %d\n", v0);
    visited[v0] = 1;
    for (int vj = 0; vj < n; vj++) {
        if (!visited[vj] && g[v0][vj] == 1)
            DepthFirstSearch2(g, n, vj);
    }
}

//7.5 采用邻接矩阵的DepthFirstSearch
void TraverseGraph2(int g[][MAXN], int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DepthFirstSearch2(g, n, i);
}


// 深度优先搜索3
void DepthFirstSearch3(AdjList g, int v0) {
    printf("Visited %d\n", v0);
    visited[v0] = 1;
    ArcNode* p = g.vertex[v0].firstarc;
    while (p != NULL) {
        if (!visited[p->adjvex])
            DepthFirstSearch3(g, p->adjvex);
        p = p->nextarc;
    }
}

//7.6 采用邻接表的DepthFirstSearch
void TraverseGraph3(AdjList g) {
    for (int i = 0; i < g.vexnum; i++) visited[i] = 0;
    for (int i = 0; i < g.vexnum; i++)
        if (!visited[i])
            DepthFirstSearch3(g, i);
}



// 深度优先搜索4（非递归）
void DepthFirstSearch4(int g[][MAXN], int n, int v0) {
    Stack s;
    InitStack(&s);
    Push(&s, v0);

    while (!Empty(&s)) {
        int v = Pop(&s);
        if (!visited[v]) {
            printf("Visited %d\n", v);
            visited[v] = 1;
        }
        for (int w = n - 1; w >= 0; w--) { // 倒序确保顺序一致
            if (g[v][w] == 1 && !visited[w])
                Push(&s, w);
        }
    }
}

//7.7 非递归形式的DepthFirstSearch
void TraverseGraph4(int g[][MAXN], int n) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DepthFirstSearch4(g, n, i);
}
// 构建用于测试的邻接矩阵图
void BuildMatrixSample(int g[][MAXN], int* n) {
    *n = 5;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *n; j++)
            g[i][j] = 0;

    g[0][1] = g[1][0] = 1;
    g[1][2] = g[2][1] = 1;
    g[3][4] = g[4][3] = 1;
}
// 构建用于测试的邻接表图
void BuildListSample(AdjList* g) {
    g->vexnum = 5;
    for (int i = 0; i < g->vexnum; i++)
        g->vertex[i].firstarc = NULL;

    int edges[][2] = {{0,1}, {1,2}, {3,4}};
    for (int i = 0; i < 3; i++) {
        int u = edges[i][0], v = edges[i][1];

        ArcNode* p1 = malloc(sizeof(ArcNode));
        p1->adjvex = v;
        p1->nextarc = g->vertex[u].firstarc;
        g->vertex[u].firstarc = p1;

        ArcNode* p2 = malloc(sizeof(ArcNode));
        p2->adjvex = u;
        p2->nextarc = g->vertex[v].firstarc;
        g->vertex[v].firstarc = p2;
    }
}