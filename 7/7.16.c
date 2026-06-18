#include <stdio.h>
#include <stdlib.h>

#define INFINITY 32767
#define MAX_VEX_NUM 30

typedef struct {
    char vexs[MAX_VEX_NUM + 1];                  // 顶点信息，从下标1开始
    int arcs[MAX_VEX_NUM + 1][MAX_VEX_NUM + 1];  // 邻接矩阵（权值）
    int vexnum, arcnum;                          // 顶点数、边数
} AdjGraph;

// 函数声明
// 创建图
AdjGraph *CreateAdjGraph();
//7.16 弗洛伊德算法
int CenterVex(AdjGraph *g);

int main() {
    int center;
    AdjGraph *g;

    g = CreateAdjGraph();
    center = CenterVex(g);

    printf("中心顶点为: %c\n", g->vexs[center]);

    return 0;
}
// 创建图
AdjGraph *CreateAdjGraph() {
    AdjGraph *g = (AdjGraph *)malloc(sizeof(AdjGraph));
    int i, j, k, x;

    printf("输入顶点数和边数(格式如: 5 7):\n");
    scanf("%d%d", &g->vexnum, &g->arcnum);

    printf("输入顶点信息(如: abcde):\n");
    getchar();  // 吃掉上一个回车
    for (i = 1; i <= g->vexnum; i++) {
        scanf("%c", &g->vexs[i]);
    }

    // 初始化邻接矩阵
    for (i = 1; i <= g->vexnum; i++) {
        for (j = 1; j <= g->vexnum; j++) {
            g->arcs[i][j] = (i == j) ? 0 : INFINITY;
        }
    }

    printf("顶点<->序号 对照表:\n");
    for (k = 1; k <= g->vexnum; k++) {
        printf("%4c <-> %d\n", g->vexs[k], k);
    }

    printf("输入每条边的两个顶点序号和权值，格式为 i j x：\n");
    for (k = 1; k <= g->arcnum; k++) {
        scanf("%d%d%d", &i, &j, &x);
        g->arcs[i][j] = x;
        // 如果是无向图，还要加上这一句：
        // g->arcs[j][i] = x;
    }

    return g;
}

//7.16 弗洛伊德算法
int CenterVex(AdjGraph *g) {
    int i, j, k;
    int min, len;
    int length[MAX_VEX_NUM + 1][MAX_VEX_NUM + 1];

    // 初始化路径矩阵
    for (i = 1; i <= g->vexnum; i++) {
        for (j = 1; j <= g->vexnum; j++) {
            length[i][j] = g->arcs[i][j];
        }
    }

    // Floyd 算法
    for (k = 1; k <= g->vexnum; k++) {
        for (i = 1; i <= g->vexnum; i++) {
            for (j = 1; j <= g->vexnum; j++) {
                if (length[i][k] < INFINITY && length[k][j] < INFINITY &&
                    length[i][k] + length[k][j] < length[i][j]) {
                    length[i][j] = length[i][k] + length[k][j];
                }
            }
        }
    }

    // 查找最小最大路径和的顶点
    min = INFINITY;
    int center = 0;

    for (i = 1; i <= g->vexnum; i++) {
        len = 0;
        for (j = 1; j <= g->vexnum; j++) {
            if (i != j && length[i][j] < INFINITY) {
                len += length[i][j];
            }
        }
        if (len < min) {
            min = len;
            center = i;
        }
    }

    return center;
}
