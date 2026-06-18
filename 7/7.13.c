#include <stdio.h>
#include <stdlib.h>
#define Null 0
#define MAX 20

typedef struct ArcNode {
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode, *AdjList;

typedef struct Graph {
    AdjList elem[MAX + 1];
    int vexnum;
    int arcnum;
    int GraphKind; // 0: 无向图, 1: 有向图
} Graph;

typedef struct Stack {
    int s[MAX];
    int top;
} Stack;


// 栈初始化
void initStack(Stack *s);
// 入栈
int Push(Stack *s, int e);
// 出栈
int Pop(Stack *s, int *e);
// 判断栈是否为空
int StackEmpty(Stack s);
// 创建图
void create(Graph *G);
// 7.13 改进的拓扑排序算法
int TopoSort(Graph G);


int main() {
    Graph G;
    printf("Please input the number of vertices, number of arcs, and GraphKind (0=Undirected, 1=Directed):\n");
    scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &G.GraphKind);

    create(&G);
    TopoSort(G);

    return 0;
}


// 栈初始化
void initStack(Stack *s) {
    s->top = 0;
}
// 入栈
int Push(Stack *s, int e) {
    if (s->top >= MAX) return 0;
    s->s[s->top++] = e;
    return 1;
}
// 出栈
int Pop(Stack *s, int *e) {
    if (s->top <= 0) return 0;
    *e = s->s[--s->top];
    return 1;
}
// 判断栈是否为空
int StackEmpty(Stack s) {
    return s.top == 0;
}
// 创建图
void create(Graph *G) {
    int i, start, end;
    AdjList p;
    for (i = 0; i <= MAX; i++)
        G->elem[i] = Null;

    printf("Enter each edge in the format: start,end\n");
    for (i = 1; i <= G->arcnum; i++) {
        printf("Edge %d: ", i);
        scanf("%d,%d", &start, &end);

        // 插入边 (start -> end)
        p = (AdjList)malloc(sizeof(ArcNode));
        p->adjvex = end;
        p->nextarc = G->elem[start];
        G->elem[start] = p;

        // 若为无向图，还需插入反向边
        if (G->GraphKind == 0) {
            p = (AdjList)malloc(sizeof(ArcNode));
            p->adjvex = start;
            p->nextarc = G->elem[end];
            G->elem[end] = p;
        }
    }
}

// 7.13 改进的拓扑排序算法
int TopoSort(Graph G) {
    int i, count = 0, indegree[MAX + 1];
    AdjList p;
    Stack S;
    initStack(&S);

    // 初始化入度
    for (i = 1; i <= G.vexnum; i++)
        indegree[i] = 0;

    for (i = 1; i <= G.vexnum; i++)
        for (p = G.elem[i]; p; p = p->nextarc)
            ++indegree[p->adjvex];

    // 将入度为0的顶点入栈
    for (i = 1; i <= G.vexnum; i++)
        if (indegree[i] == 0)
            Push(&S, i);

    // 开始拓扑排序
    printf("The result of TopoSort is:\n");
    while (!StackEmpty(S)) {
        Pop(&S, &i);
        printf("v%d ", i);
        count++;
        for (p = G.elem[i]; p; p = p->nextarc) {
            if (--indegree[p->adjvex] == 0)
                Push(&S, p->adjvex);
        }
    }

    // 判断是否成功
    if (count < G.vexnum) {
        printf("\nCycle detected! Topological sort failed.\n");
        return 1;
    } else {
        printf("\nTopological sort successful.\n");
        return 0;
    }
}