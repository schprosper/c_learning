#include <stdio.h>
#include <stdlib.h>

#define INFINITY 10000
#define VERTEX_NUM 7  // 顶点编号1-6，0不使用
#define EDGE_NUM 9

int Graph[VERTEX_NUM][VERTEX_NUM] = {
// 0     1     2     3     4     5     6
{INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY},  // 0
{INFINITY, INFINITY, 6, 3, INFINITY, INFINITY, INFINITY},  // 1
{INFINITY, INFINITY, INFINITY, INFINITY, 5, INFINITY, INFINITY},  // 2
{INFINITY, INFINITY, 2, INFINITY, 3, 4, INFINITY},  // 3
{INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, 3},  // 4
{INFINITY, INFINITY, INFINITY, INFINITY, 2, INFINITY, 5},  // 5
{INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY, INFINITY}   // 6
};

int Visited[VERTEX_NUM];
int Path[VERTEX_NUM];
int Distance[VERTEX_NUM];

//7.15 图的最短路径算法
void Dijkstra(int Start) ;


int main() {
    int i, k;

    // 初始化
    for (i = 0; i < VERTEX_NUM; i++) {
        Visited[i] = 0;
        Path[i] = 1;  // 默认前驱都是起点1
    }

    printf("Dijkstra Algorithm Steps:\n");
    Dijkstra(1);

    // 输出所有最短路径
    printf("\nAll Shortest Paths from Vertex 1:\n");
    printf("------------------------------\n");
    for (i = 2; i < VERTEX_NUM; i++) {
        printf("To %d (Distance: %2d): ", i, Distance[i]);
        k = i;

        // 反向追踪路径
        do {
            printf("%d", k);
            if (Path[k] != 1) printf(" <- ");
            k = Path[k];
        } while (k != 1);

        printf(" <- 1\n");
    }

    return 0;
}

//7.15 图的最短路径算法
void Dijkstra(int Start) {
    int MinEdge, CurrentVertex, i, j, Step;
    Step = 1;
    Visited[Start] = 1;

    // 初始化距离数组
    for (i = 1; i < VERTEX_NUM; i++) {
        Distance[i] = Graph[Start][i];
    }
    Distance[Start] = 0;

    // 打印表头
    printf("Step  ");
    for (i = 1; i < VERTEX_NUM; i++) {
        printf("%3d ", i);
    }
    printf("\n--------------------------------\n");

    // 初始状态输出
    printf("%2d: ", Step);
    for (i = 1; i < VERTEX_NUM; i++) {
        if (Distance[i] == INFINITY) printf("  * ");
        else printf("%3d ", Distance[i]);
    }
    printf("\n");

    // 主循环
    while (Step < VERTEX_NUM - 1) {
        Step++;
        MinEdge = INFINITY;

        // 找到当前最小距离的顶点
        for (j = 1; j < VERTEX_NUM; j++) {
            if (Visited[j] == 0 && MinEdge > Distance[j]) {
                CurrentVertex = j;
                MinEdge = Distance[j];
            }
        }

        Visited[CurrentVertex] = 1;
        printf("%2d: ", Step);

        // 更新邻接顶点距离
        for (j = 1; j < VERTEX_NUM; j++) {
            if (Visited[j] == 0 && Distance[CurrentVertex] + Graph[CurrentVertex][j] < Distance[j]) {
                Distance[j] = Distance[CurrentVertex] + Graph[CurrentVertex][j];
                Path[j] = CurrentVertex;
            }

            // 打印当前距离
            if (Distance[j] == INFINITY) printf("  * ");
            else printf("%3d ", Distance[j]);
        }
        printf("\n");
    }
}
