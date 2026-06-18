#include <stdio.h>

#define Max 0x7ffff        // 表示无边
#define MAXV 100        // 最大顶点数

typedef struct {
    int vertex_num;             // 顶点数
    int edge_num;               // 边数
    char vertex[MAXV];          // 顶点数组
    int arc[MAXV][MAXV];        // 邻接矩阵
} Mat_Grph;


// 创建图
void create_graph(Mat_Grph* G) {
    G->vertex_num = 4;      // 顶点编号：0~3
    G->edge_num = 5;        // 5 条边

    // 初始化顶点标识（可选）
    for (int i = 0; i < G->vertex_num; i++) {
        G->vertex[i] = '0' + i;
    }

    // 初始化邻接矩阵，默认全部为 Max，表示无边
    for (int i = 0; i < G->vertex_num; i++) {
        for (int j = 0; j < G->vertex_num; j++) {
            G->arc[i][j] = Max;

            if (i == j) {
                G->arc[i][j] = 0;
            }
        }
    }

    // 添加边及其权值（由图提供）
    G->arc[0][3] = 3;      // 0 -> 3，权值为 3
    G->arc[1][0] = 5;      // 1 -> 0，权值为 5
    G->arc[1][2] = 2;      // 1 -> 2，权值为 2
    G->arc[2][0] = 6;      // 2 -> 0，权值为 6
    G->arc[2][1] = 4;      // 2 -> 1，权值为 4
}


// 打印邻接矩阵
void print_matrix(Mat_Grph G) {
    printf("Matrix:\n");

    for (int i = 0; i < G.vertex_num; i++) {
        for (int j = 0; j < G.vertex_num; j++) {
            if (G.arc[i][j] == Max) {
                printf("%4s", "Max");
            } else {
                printf("%4d", G.arc[i][j]);
                //占 4 个字符宽度，右对齐
            }
        }
        printf("\n");
    }
}


int main() {
    Mat_Grph G;          // 定义一个图结构体变量

    create_graph(&G);    // 构建邻接矩阵
    print_matrix(G);     // 输出邻接矩阵

    return 0;
}