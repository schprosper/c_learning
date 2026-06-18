#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10
#define INFINITY INT_MAX

typedef int AdjMatrix[N][N]; // 邻接矩阵

// 树边结构
typedef struct {
    int fromvex, tovex;  // 边的起点和终点
    int length;          // 边权
} TreeEdgeNode;

typedef TreeEdgeNode MST[N - 1]; // 最小生成树类型

AdjMatrix G;  // 图的邻接矩阵
MST T;        // 存储最小生成树的边


// 打印错误信息并退出
void Error(const char *msg);
// 默认建图函数
void DefaultCreateGraph(AdjMatrix G);
// 初始化候选边集
void InitCandidateSet(AdjMatrix G, MST T, int r);
// 从候选边中选择最短边
int SelectLightEdge(MST T, int k);
// 修改候选边集
void ModifyCandidateSet(AdjMatrix G, MST T, int k, int v);
// 7.10 普利姆算法（边集维护方式）
void PrimMST(AdjMatrix G, MST T, int r);
//ppt p32 Prim算法（顶点距离维护方式）
void Prim_Vertices(AdjMatrix G, int v);
// 输出最小生成树
void PrintMST(MST T);
// ppt p41 Kruskal算法
void Kruskal(AdjMatrix g);




// 主函数
int main() {
    int start;

    printf("普利姆算法演示（使用默认图）\n");
    DefaultCreateGraph(G);

    printf("请输入普利姆算法的起始顶点编号 (0 ~ %d): ", N - 1);
    scanf("%d", &start);


    PrimMST(G, T, start);
    PrintMST(T);

    return 0;
}


// 打印错误信息并退出
void Error(const char *msg) {
    printf("错误: %s\n", msg);
    exit(1);
}

// 默认建图函数
void DefaultCreateGraph(AdjMatrix G) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            G[i][j] = INFINITY;

    // 手动设置边
    G[0][1] = G[1][0] = 4;
    G[1][2] = G[2][1] = 2;
    G[0][3] = G[3][0] = 3;
    G[1][5] = G[5][1] = 1;
    G[3][6] = G[6][3] = 10;
    G[6][9] = G[9][6] = 5;
    G[9][7] = G[7][9] = 2;
    G[7][8] = G[8][7] = 6;
    G[3][4] = G[4][3] = 8;
    G[4][5] = G[5][4] = 1;
    G[2][5] = G[5][2] = 2;
    G[4][7] = G[7][4] = 4;
    G[5][8] = G[8][5] = 4;
}

// 初始化候选边集
void InitCandidateSet(AdjMatrix G, MST T, int r) {
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (i != r) {
            T[k].fromvex = r;
            T[k].tovex = i;
            T[k++].length = G[r][i];
        }
    }
}

// 从候选边中选择最短边
int SelectLightEdge(MST T, int k) {
    int min = INFINITY, minpos = -1;
    for (int i = k; i < N - 1; i++) {
        if (T[i].length < min) {
            min = T[i].length;
            minpos = i;
        }
    }
    if (minpos == -1)
        Error("图不连通，无法生成最小生成树！");
    return minpos;
}

// 修改候选边集
void ModifyCandidateSet(AdjMatrix G, MST T, int k, int v) {
    for (int i = k; i < N - 1; i++) {
        int d = G[v][T[i].tovex];
        if (d < T[i].length) {
            T[i].length = d;
            T[i].fromvex = v;
        }
    }
}

// 7.10 普利姆算法（边集维护方式）
void PrimMST(AdjMatrix G, MST T, int r) {
    InitCandidateSet(G, T, r);
    for (int k = 0; k < N - 1; k++) {
        int m = SelectLightEdge(T, k);
        TreeEdgeNode temp = T[k];
        T[k] = T[m];
        T[m] = temp;

        int v = T[k].tovex;
        ModifyCandidateSet(G, T, k + 1, v);
    }
}

// ppt p32 Prim算法（顶点距离维护方式）
void Prim_Vertices(AdjMatrix G, int v) {
    int lowcost[N];     // 顶点到U的最小距离
    int closest[N];     // 顶点的最近邻接顶点
    int i, j, k, min;
    
    // 初始化：从顶点v开始
    for (i = 0; i < N; i++) {
        lowcost[i] = G[v][i];   // 所有顶点到起点v的距离
        closest[i] = v;          // 最近邻接顶点初始为v
    }
    
    // 输出(N-1)条边
    for (i = 1; i < N; i++) {
        min = INFINITY;
        k = -1;
        
        // 在(V-U)中找出离U最近的顶点k
        for (j = 0; j < N; j++) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;  // k记录最近顶点编号
            }
        }
        
        if (k == -1) {
            Error("图不连通，无法生成最小生成树！");
        }
        
        printf("  边(%d, %d) 权为: %d\n", closest[k], k, min);
        lowcost[k] = 0;  // 标记k已经加入U
        
        // 修改数组lowcost和closest
        for (j = 0; j < N; j++) {
            if (lowcost[j] != 0 && G[k][j] < lowcost[j]) {
                lowcost[j] = G[k][j];
                closest[j] = k;
            }
        }
    }
}

// 输出最小生成树
void PrintMST(MST T) {
    int totalWeight = 0;
    printf("最小生成树边集如下：\n");
    for (int i = 0; i < N - 1; i++) {
        printf("(%d, %d) 权重 = %d\n", T[i].fromvex, T[i].tovex, T[i].length);
        totalWeight += T[i].length;
    }
    printf("总权重 = %d\n", totalWeight);
}


// ppt p41 Kruskal算法
void Kruskal(AdjMatrix g) {
    int i, j, u1, v1, sn1, sn2, k; // 临时变量、一条边的头尾顶点序号、两个顶点所属的集合编号、边数组的下标
    int vset[N];                   // 连通分量编号数组
    TreeEdgeNode E[N * (N - 1) / 2]; // 存放所有边

    int edgeCount = 0;             // E数组的下标从0开始计

    // 由g产生的边集E
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            if (g[i][j] != INFINITY) { // 若顶点i和j间权值不为无穷大，即相邻接
                E[edgeCount].fromvex = i;
                E[edgeCount].tovex = j;
                E[edgeCount].length = g[i][j]; // 边的起始、终止顶点序号、权值
                edgeCount++; // 下一个边
            }
        }
    }

    // E数组按权值递增排序，便于找权值最小边
    for (i = 0; i < edgeCount - 1; i++) {
        for (j = 0; j < edgeCount - 1 - i; j++) {
            if (E[j].length > E[j + 1].length) {
                TreeEdgeNode temp = E[j];
                E[j] = E[j + 1];
                E[j + 1] = temp;
            }
        }
    }

    // 初始化辅助数组：连通分量编号数组
    for (i = 0; i < N; i++) {
        vset[i] = i; // 连通分量编号
    }

    k = 1; // k当前构造生成树的第几条边，初值为1
    j = 0; // E中边的下标，初值为0

    while (k < N && j < edgeCount) { // 生成的边数小于n时循环
        u1 = E[j].fromvex;
        v1 = E[j].tovex; // 取一条边的头尾顶点

        sn1 = vset[u1];
        sn2 = vset[v1]; // 分别得到两个顶点所属的集合编号

        if (sn1 != sn2) { // 两顶点属于不同的集合
            T[k - 1] = E[j];

            k++; // 生成边数增1

            for (i = 0; i < N; i++) {
                if (vset[i] == sn2) { // 集合编号为sn2的改为sn1
                    vset[i] = sn1;
                }
            }
        }

        j++; // 扫描下一条边
    }

    if (k < N) {
        Error("图不连通，无法生成最小生成树！");
    }
}