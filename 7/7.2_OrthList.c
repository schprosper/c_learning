#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 10
#define INFINITY 32768
#define True 1
#define False 0
#define Error -1
#define Ok 1

typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef char VertexData;

typedef struct ArcNode {
    int tailvex, headvex;
    struct ArcNode *hlink, *tlink;
} ArcNode;

typedef struct VertexNode {
    VertexData data;
    ArcNode *firstin, *firstout;
} VertexNode;

typedef struct {
    VertexNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphKind kind;
} OrthList;







//在图中定位顶点
int LocateVertex(OrthList *G, VertexData v);
//7.2 创建图的十字链表
void CrtOrthList(OrthList *g);
// 打印十字链表
void PrintOrthList(OrthList *g);



int main() {
    OrthList g;
    CrtOrthList(&g);
    PrintOrthList(&g);
    return 0;
}

//在图中定位顶点
int LocateVertex(OrthList *G, VertexData v) {
    int j = Error, k;
    for (k = 0; k < G->vexnum; k++)
        if (G->vertex[k].data == v) {
            j = k;
            break;
        }
    return j;
}

//7.2 创建图的十字链表
void CrtOrthList(OrthList *g) {
    int n, e;
    int i, j, k;
    char vt, vh;
    ArcNode *p; //弧节点链表

    printf("请输入图的顶点个数和弧的个数（格式如：3 4）:\n");
    scanf("%d %d", &n, &e);
    g->vexnum = n;
    g->arcnum = e;

    for (i = 0; i < n; i++) {
        printf("请输入第 %d 个顶点字符：", i + 1);
        scanf("% c", &g->vertex[i].data);
        g->vertex[i].firstin = NULL;
        g->vertex[i].firstout = NULL;
    }

    for (k = 0; k < e; k++) {
        printf("请输入第 %d 条弧的起点和终点（格式如：A B）:\n", k + 1);
        scanf(" %c %c", &vt, &vh);
        i = LocateVertex(g, vt);
        j = LocateVertex(g, vh);

        if (i == Error || j == Error) {
            printf("输入的顶点不存在！跳过此边。\n");
            continue;
        }

        p = (ArcNode *)malloc(sizeof(ArcNode));
        p->tailvex = i;
        p->headvex = j;

        // 插入尾顶点 i 的出边表
        p->tlink = g->vertex[i].firstout;
        g->vertex[i].firstout = p;

        // 插入头顶点 j 的入边表
        p->hlink = g->vertex[j].firstin;
        g->vertex[j].firstin = p;
    }
}
// 打印十字链表
void PrintOrthList(OrthList *g) {
    printf("\n=== 图的十字链表结构如下 ===\n");
    for (int i = 0; i < g->vexnum; i++) {
        printf("顶点 %c 的出边：", g->vertex[i].data);
        ArcNode *p = g->vertex[i].firstout;
        while (p) {
            printf("(%c -> %c) ", g->vertex[p->tailvex].data, g->vertex[p->headvex].data);
            p = p->tlink;
        }
        printf("\n");

        printf("顶点 %c 的入边：", g->vertex[i].data);
        p = g->vertex[i].firstin;
        while (p) {
            printf("(%c -> %c) ", g->vertex[p->tailvex].data, g->vertex[p->headvex].data);
            p = p->hlink;
        }
        printf("\n");
    }
}
