#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define Error -1
#define Ok 1

/* 邻接表结构定义 */
typedef struct ArcNode {
    int adjvex;                 // 邻接点下标
    int weight;                // 权重（可省略）
    struct ArcNode *nextarc;   // 下一条边
} ArcNode;

typedef struct VertexNode {
    char data;                // 顶点名
    ArcNode *firstarc;        // 第一条边
} VertexNode;

typedef struct {
    VertexNode vertexes[MAX_VERTEX_NUM];
    int vexnum;   // 顶点数
    int arcnum;   // 边数
} Graph;

/* 栈结构 */
typedef struct {
    int data[MAX_VERTEX_NUM];
    int top;
} Stack;

// 栈初始化
void InitStack(Stack *S);
// 入栈
int Push(Stack *S, int x);
// 出栈
int Pop(Stack *S, int *x);
// 判断栈是否为空
int IsEmpty(Stack S);
// 计算每个顶点的入度
void FindID(Graph G, int indegree[MAX_VERTEX_NUM]);
//7.11 拓扑排序 
int TopoSort(Graph G);
/* 创建样例图 A→B, A→C, B→D, C→D, D→E */
void CreateSampleGraph(Graph *G);


int main() {
    Graph G;
    CreateSampleGraph(&G);
    printf("拓扑排序结果:\n");
    if (TopoSort(G) == Error)
        printf("\n该图有环，无法进行拓扑排序。\n");
    else
        printf("\n拓扑排序成功。\n");
    return 0;
}


// 栈初始化
void InitStack(Stack *S) {
    S->top = 0;
}
// 入栈
int Push(Stack *S, int x) {
    if (S->top >= MAX_VERTEX_NUM) return 0;
    S->data[S->top++] = x;
    return 1;
}
// 出栈
int Pop(Stack *S, int *x) {
    if (S->top <= 0) return 0;
    *x = S->data[--S->top];
    return 1;
}
// 判断栈是否为空
int IsEmpty(Stack S) {
    return S.top == 0;
}



/* 求每个顶点的入度 */
void FindID(Graph G, int indegree[MAX_VERTEX_NUM]) {
    for (int i = 0; i < G.vexnum; i++)
        indegree[i] = 0;

    for (int i = 0; i < G.vexnum; i++) {
        ArcNode *p = G.vertexes[i].firstarc;
        while (p != NULL) {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
}

//7.11 拓扑排序
int TopoSort(Graph G) {
    Stack S;
    int indegree[MAX_VERTEX_NUM];
    int i, count, k;
    ArcNode *p;

    FindID(G, indegree);  // 计算入度
    InitStack(&S);

    for (i = 0; i < G.vexnum; i++)
        if (indegree[i] == 0)
            Push(&S, i);  // 将入度为0的顶点入栈

    count = 0;
    while (!IsEmpty(S)) {
        Pop(&S, &i);
        printf("%c ", G.vertexes[i].data);
        count++;  // 输出并统计
        p = G.vertexes[i].firstarc;
        while (p != NULL) {
            k = p->adjvex;
            indegree[k]--;
            if (indegree[k] == 0)
                Push(&S, k);
            p = p->nextarc;
        }
    }

    if (count < G.vexnum)
        return Error;  // 有环
    else
        return Ok;
}

/* 创建样例图 A→B, A→C, B→D, C→D, D→E */
void CreateSampleGraph(Graph *G) {
    int i;
    G->vexnum = 5;
    G->arcnum = 5;

    for (i = 0; i < G->vexnum; i++) {
        G->vertexes[i].data = 'A' + i;
        G->vertexes[i].firstarc = NULL;
    }

    ArcNode *p;

    // A → B
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 1;
    p->nextarc = G->vertexes[0].firstarc;
    G->vertexes[0].firstarc = p;

    // A → C
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 2;
    p->nextarc = G->vertexes[0].firstarc;
    G->vertexes[0].firstarc = p;

    // B → D
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 3;
    p->nextarc = G->vertexes[1].firstarc;
    G->vertexes[1].firstarc = p;

    // C → D
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 3;
    p->nextarc = G->vertexes[2].firstarc;
    G->vertexes[2].firstarc = p;

    // D → E
    p = (ArcNode *)malloc(sizeof(ArcNode));
    p->adjvex = 4;
    p->nextarc = G->vertexes[3].firstarc;
    G->vertexes[3].firstarc = p;
}