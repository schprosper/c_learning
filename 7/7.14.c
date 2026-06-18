#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for toupper

#define MAX_PROJECT_NUM 100

typedef struct node {
    int adjvex;
    int dut;
    struct node *next;
} edgenode;

typedef struct {
    int projectname;
    int id; // 入度
    edgenode *link;
} vexnode;

// 创建图
void CreateGraphic(vexnode *Graphicmap, int projectnumber, int activenumber);
//7.14 关键路径算法
int SearchMapPath(vexnode *Graphicmap, int projectnumber, int activenumber, int *totaltime);
// 关键路径算法主函数
void seekkeyroot() ;



int main() {
    char ch;
    int i;
    while (1) {
        do {
            system("cls");
            printf("************ 关键路径算法程序 ************\n");
            printf("(S)tart 开始输入工程数据并求关键路径\n");
            printf("(E)xit 退出程序\n");
            printf("请输入选择: ");
            scanf(" %c", &ch);
            ch = toupper(ch);
        } while (ch != 'S' && ch != 'E');

        switch (ch) {
        case 'S':
            seekkeyroot();
            break;
        case 'E':
            return 0;
        }
    }
}


// 创建图
void CreateGraphic(vexnode* Graphicmap, int projectnumber, int activenumber)
{
    int begin, end, duttem;
    int i, k;
    edgenode *p;

    // 初始化图的节点
    for (i = 0; i < projectnumber; i++)
    {
        Graphicmap[i].projectname = i;
        Graphicmap[i].id = 0;
        Graphicmap[i].link = NULL;
    }

    printf("请输入每条活动的信息，格式为<vi,vj,dut>\n");
    printf("如：3,4,9 回车表示第三节点到第四节点之间的活动用了9个单位时间\n");

    // 清除输入缓冲区的残留数据
    while (getchar() != '\n');

    // 输入每条边的信息
    for (k = 0; k < activenumber; k++)
    {
        char line[100];
        printf("请输入第 %d 条边（格式：i,j,d）：", k + 1);

        // 使用 fgets 读取整行
        fgets(line, sizeof(line), stdin);

        // 如果读取到换行符，跳过
        if (line[0] == '\n') {
            k--;  // 重新输入当前边
            continue;
        }

        // 使用 sscanf 从行数据中提取数据
        sscanf(line, "%d,%d,%d", &begin, &end, &duttem);

        // 动态分配并创建边
        p = (edgenode*)malloc(sizeof(edgenode));
        p->adjvex = end - 1;  // 将顶点编号从1调整为0开始
        p->dut = duttem;
        Graphicmap[end - 1].id++;
        p->next = Graphicmap[begin - 1].link;
        Graphicmap[begin - 1].link = p;
    }
}

//7.14 关键路径算法
int SearchMapPath(vexnode *Graphicmap, int projectnumber, int activenumber, int *totaltime) {
    int i, j, k, m = 0, front = -1, rear = -1;
    edgenode *p;
    int *topologystack = (int *)malloc(projectnumber * sizeof(int));
    int *vl = (int *)malloc(projectnumber * sizeof(int));
    int *ve = (int *)malloc(projectnumber * sizeof(int));
    int *l = (int *)malloc(activenumber * sizeof(int));
    int *e = (int *)malloc(activenumber * sizeof(int));

    // 初始化最早开始时间
    for (i = 0; i < projectnumber; i++) ve[i] = 0;

    // 拓扑排序，初始化入度为0的节点
    for (i = 0; i < projectnumber; i++) {
        if (Graphicmap[i].id == 0) {
            topologystack[++rear] = i;
            m++;
        }
    }

    // 计算最早开始时间ve
    while (front != rear) {
        front++;
        j = topologystack[front];
        p = Graphicmap[j].link;
        while (p) {
            k = p->adjvex;
            Graphicmap[k].id--;
            if (ve[j] + p->dut > ve[k])
                ve[k] = ve[j] + p->dut;
            if (Graphicmap[k].id == 0)
                topologystack[++rear] = k;
            p = p->next;
        }
    }

    // 检查是否有环
    if (rear + 1 < projectnumber) {
        printf("\n图中存在环，无法计算关键路径。\n");
        return 0;
    }

    *totaltime = ve[projectnumber - 1];
    for (i = 0; i < projectnumber; i++) vl[i] = *totaltime;

    // 计算最迟开始时间vl
    for (i = projectnumber - 2; i >= 0; i--) {
        j = topologystack[i];
        p = Graphicmap[j].link;
        while (p) {
            k = p->adjvex;
            if (vl[k] - p->dut < vl[j])
                vl[j] = vl[k] - p->dut;
            p = p->next;
        }
    }

    // 输出活动的起点、终点、最早开始、最迟开始、差值及状态
    i = 0;
    printf("| 起点 | 终点 | 最早开始 | 最迟开始 | 差值 |   状态   |\n");
    printf("--------------------------------------------------------\n");
    for (j = 0; j < projectnumber; j++) {
        p = Graphicmap[j].link;
        while (p) {
            k = p->adjvex;
            e[++i] = ve[j];
            l[i] = vl[k] - p->dut;

            // 打印每条活动的结果
            printf("| %4d | %4d |   %5d   |   %5d   | %4d |",
                   Graphicmap[j].projectname + 1, Graphicmap[k].projectname + 1,
                   e[i], l[i], l[i] - e[i]);

            // 如果差值为0，表示关键活动
            if (l[i] == e[i])
                printf(" 关键活动");
            printf("\n");
            p = p->next;
        }
    }

    // 输出整个工程的最短工期
    printf("整个工程的最短工期为：%d 个单位时间\n", *totaltime);

    // 释放内存
    free(topologystack);
    free(vl);
    free(ve);
    free(l);
    free(e);
    return 1;
}
// 关键路径算法主函数
void seekkeyroot() {
    int projectnumber, activenumber, totaltime = 0;
    vexnode *Graphicmap;
    system("cls");
    printf("请输入工程的节点数：");
    scanf("%d", &projectnumber);
    printf("请输入工程的活动数：");
    scanf("%d", &activenumber);
    Graphicmap = (vexnode *)malloc(projectnumber * sizeof(vexnode));
    CreateGraphic(Graphicmap, projectnumber, activenumber);
    if (SearchMapPath(Graphicmap, projectnumber, activenumber, &totaltime)) {
        printf("整个工程的最短工期为：%d 个单位时间\n", totaltime);
    }
    system("pause");
    free(Graphicmap);
}