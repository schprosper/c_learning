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

typedef struct ArcNode {
    int adj;  // 权值（或是否相邻）
} ArcNode;

typedef struct {
    VertexData vexs[MAX_VERTEX_NUM];                   // 顶点数组
    ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];      // 邻接矩阵
    int vexnum, arcnum; // 总的顶点数和弧数。
    GraphKind kind;
} AdjMatrix;


//在图中定位顶点
int LocateVertex(AdjMatrix *G, VertexData v);
//7.1 采用邻接矩阵表示法创建有向图
int CreateDN(AdjMatrix *G);
// 打印邻接矩阵
void PrintMatrix(AdjMatrix *G);


int main() {
    AdjMatrix G;
    CreateDN(&G);
    PrintMatrix(&G);
    return 0;
}



//在图中定位顶点
int LocateVertex(AdjMatrix *G, VertexData v) {
    for (int k = 0; k < G->vexnum; k++)
        if (G->vexs[k] == v)
            return k;
    return Error;
}

//7.1 采用邻接矩阵表示法创建有向图
int CreateDN(AdjMatrix *G) {
    int i, j, k, weight;
    VertexData v1, v2;

    printf("请输入图的顶点数和弧数（如：3 4）:\n");
    scanf("%d %d", &G->vexnum, &G->arcnum);

    // 初始化邻接矩阵
    for (i = 0; i < G->vexnum; i++)
        for (j = 0; j < G->vexnum; j++)
            G->arcs[i][j].adj = INFINITY;

    // 输入顶点
    for (i = 0; i < G->vexnum; i++) {
        printf("请输入第 %d 个顶点字符: ", i + 1);
        (" %c", &G->vexs[i]);
    }

    // 输入边
    for (k = 0; k < G->arcnum; k++) {
        printf("请输入第 %d 条边的两个顶点及权值（如：A B 5）:\n", k + 1);
        scanf(" %c %c %d", &v1, &v2, &weight);
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);
        if (i == Error || j == Error) {
            printf("错误：顶点不存在，跳过该边。\n");
            continue;
        }
        G->arcs[i][j].adj = weight;
    }

    return Ok;
}
// 打印邻接矩阵
void PrintMatrix(AdjMatrix *G) {
    printf("\n=== 邻接矩阵如下 ===\n");
    printf("   ");
    for (int i = 0; i < G->vexnum; i++)
        printf(" %c ", G->vexs[i]);
    printf("\n");

    for (int i = 0; i < G->vexnum; i++) {
        printf("%c ", G->vexs[i]);
        for (int j = 0; j < G->vexnum; j++) {
            if (G->arcs[i][j].adj == INFINITY)
                printf(" ∞ ");
            else
                printf("%2d ", G->arcs[i][j].adj);
        }
        printf("\n");
    }
}