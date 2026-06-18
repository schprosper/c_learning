
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char VertexType;
typedef int Edge;

/*结构体定义：到时候，是顶点矩阵和边矩阵一起来看*/
typedef struct 
{
    VertexType vertex[MAXSIZE]; //顶点数组（矩阵表头）
    Edge arc[MAXSIZE][MAXSIZE];
    int edge_num;
    int vertex_num;
}Mat_Graph;

/*创建邻接矩阵*/
void createGraph(Mat_Graph *G)
{
    G->edge_num = 5;
    G->vertex_num = 4;

    //顶点命名
    G->vertex[0] = '0';
    G->vertex[1] = '1';
    G->vertex[2] = '2';
    G->vertex[3] = '3';


    for(int i =0 ; i<G->vertex_num;i++)
    {
        for(int j =0 ; j<G->vertex_num;j++)
        {
            G->arc[i][j] = 0;
        }
    }
    //赋值，但它是从0开始的
    G->arc[0][1] = 1;    G->arc[1][0] = 1;    // V0-V1
    G->arc[0][2] = 1;    G->arc[2][0] = 1;    // V0-V2
    G->arc[0][3] = 1;    G->arc[3][0] = 1;    // V0-V3
    G->arc[1][2] = 1;    G->arc[2][1] = 1;    // V1-V2
    G->arc[2][3] = 1;    G->arc[3][2] = 1;    // V2-V3
}

void print_matrix(Mat_Graph G)
{
    printf("Matrix:\n");

    for(int i =0 ; i<G.vertex_num;i++)
    {
        for(int j =0 ; j<G.vertex_num;j++)
        {
            printf("%d ",G.arc[i][j]);
        }
        printf("\n");
    }
}

/*带权值：*/

int main()
{
    Mat_Graph G;
    createGraph(&G);
    print_matrix(G);
    return 1;

}