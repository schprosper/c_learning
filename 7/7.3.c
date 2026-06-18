#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int arcs[MAX_VERTICES][MAX_VERTICES];  // 邻接矩阵
    int vexnum; // 顶点个数
} Graph;

bool visited[MAX_VERTICES];

// 访问函数：打印顶点编号
void visit(int v);
// 返回顶点 v 的第一个邻接点编号
int FirstAdjVertex(Graph g, int v);
// 返回 v 相对于 w 的下一个邻接点
int NextAdjVertex(Graph g, int v, int w);
// 深度优先搜索
void DepthFirstSearch(Graph g, int v0);
//7.3 深度优先遍历图
void TraverseGraph(Graph g);
// 测试函数
void TestTraverseGraph();



int main() {
  TestTraverseGraph();
}


// 访问函数：打印顶点编号
void visit(int v) {
    printf("%d ", v);
}

// 返回顶点 v 的第一个邻接点编号
int FirstAdjVertex(Graph g, int v) {
    for (int j = 0; j < g.vexnum; j++) {
        if (g.arcs[v][j] == 1)
            return j;
    }
    return -1;
}

// 返回 v 相对于 w 的下一个邻接点
int NextAdjVertex(Graph g, int v, int w) {
    for (int j = w + 1; j < g.vexnum; j++) {
        if (g.arcs[v][j] == 1)
            return j;
    }
    return -1;
}
// 深度优先搜索
void DepthFirstSearch(Graph g, int v0) {
    visit(v0);
    visited[v0] = true;
    int w = FirstAdjVertex(g, v0);
    while (w != -1) {
        if (!visited[w])
            DepthFirstSearch(g, w);
        w = NextAdjVertex(g, v0, w);
    }
}

//7.3 深度优先遍历图
void TraverseGraph(Graph g) {
    for (int i = 0; i < g.vexnum; i++)
        visited[i] = false;

    for (int i = 0; i < g.vexnum; i++) {
        if (!visited[i])
            DepthFirstSearch(g, i);
    }
}
// 测试函数
void TestTraverseGraph() {
    Graph g;
    g.vexnum = 6;

    // 初始化邻接矩阵
    for (int i = 0; i < g.vexnum; i++)
        for (int j = 0; j < g.vexnum; j++)
            g.arcs[i][j] = 0;

    // 构造两个连通分量
    // 连通分量1: 0-1-2
    g.arcs[0][1] = g.arcs[1][0] = 1;
    g.arcs[1][2] = g.arcs[2][1] = 1;

    // 连通分量2: 3-4, 4-5
    g.arcs[3][4] = g.arcs[4][3] = 1;
    g.arcs[4][5] = g.arcs[5][4] = 1;

    printf("TraverseGraph (DFS on full graph with components): ");
    TraverseGraph(g);
    printf("\n");
}