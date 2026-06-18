#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define INFINITY 32768

typedef char VertexData;

// 邻接矩阵图结构
typedef struct {
    VertexData vexs[MAX_VERTEX_NUM];
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int vexnum, arcnum;
} Graph;

// 记录路径
int pre[MAX_VERTEX_NUM];

// 辅助函数：定位顶点
int LocateVertex(Graph *G, VertexData v);
// 获取顶点 u 的第一个邻接点
int firstadj(Graph *G, int u);
// 获取 u 相对于 w 的下一个邻接点
int nextadj(Graph *G, int u, int w);
// 打印从某起点到v的路径
void print_path(int pre[], int v);
// 7.9深度优先搜索找从顶点u到v的简单路径
void DFS_path(Graph *G, int u, int v);
// 查找路径的主函数
void one_path(Graph *G, int u, int v);
// 构造样例图
void CreateSampleGraph(Graph *G);   



// 主函数
int main() {
    Graph G;
    CreateSampleGraph(&G);
    int u = LocateVertex(&G, 'A'); // 起点 A
    int v = LocateVertex(&G, 'F'); // 终点 F
    printf("从 A 到 F 的路径查找：\n");
    one_path(&G, u, v);
    return 0;
}

// 辅助函数：定位顶点
int LocateVertex(Graph *G, VertexData v) {
    for (int i = 0; i < G->vexnum; i++)
        if (G->vexs[i] == v) return i;
    return -1;
}

// 获取顶点 u 的第一个邻接点
int firstadj(Graph *G, int u) {
    for (int i = 0; i < G->vexnum; i++)
        if (G->arcs[u][i] != INFINITY)
            return i;
    return -1;
}

// 获取 u 相对于 w 的下一个邻接点
int nextadj(Graph *G, int u, int w) {
    for (int i = w + 1; i < G->vexnum; i++)
        if (G->arcs[u][i] != INFINITY)
            return i;
    return -1;
}

// 打印从某起点到v的路径
void print_path(int pre[], int v) {
    int path[MAX_VERTEX_NUM], len = 0;
    int cur = v;
    while (pre[cur] != cur) {
        path[len++] = cur;
        cur = pre[cur];
    }
    path[len++] = cur;

    printf("路径为：");
    for (int i = len - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

// 7.9深度优先搜索找从顶点u到v的简单路径
void DFS_path(Graph *G, int u, int v) {
    if (pre[v] != -1) return;  // 找到了
    for (int j = firstadj(G, u); j >= 0; j = nextadj(G, u, j)) {
        if (pre[j] == -1) {
            pre[j] = u;
            if (j == v)
                print_path(pre, v);
            else
                DFS_path(G, j, v);
        }
    }
}

// 查找路径的主函数
void one_path(Graph *G, int u, int v) {
    for (int i = 0; i < G->vexnum; i++)
        pre[i] = -1;
    pre[u] = u;
    DFS_path(G, u, v);
}

// 构造样例图
void CreateSampleGraph(Graph *G) {
    G->vexnum = 6;
    G->arcnum = 7;
    char vs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    for (int i = 0; i < G->vexnum; i++)
        G->vexs[i] = vs[i];

    for (int i = 0; i < G->vexnum; i++)
        for (int j = 0; j < G->vexnum; j++)
            G->arcs[i][j] = INFINITY;

    // 添加无向边
    int edges[7][2] = {
        {0, 1}, {0, 2}, {1, 3},
        {2, 3}, {3, 4}, {4, 5}, {1, 5}
    };
    for (int i = 0; i < G->arcnum; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        G->arcs[u][v] = G->arcs[v][u] = 1;
    }
}