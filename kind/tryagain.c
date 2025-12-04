#include <stdio.h>  // 补充标准输入输出头文件

// 必须先定义结构体point，否则编译器不知道其成员
struct point {
    int x;  // 坐标x
    int y;  // 坐标y
};

// 函数声明（保持不变）
struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point *p);

int main(int argc, char const *argv[])
{
    struct point y = {0, 0};  // 初始化结构体变量y
    getStruct(&y);            // 传入y的地址，修改y的值
    output(y);                // 输出修改后的y
    output(*getStruct(&y));    // 再次修改y并输出
    print(getStruct(&y));     // 再次修改y并通过指针输出
    return 0;  // main函数建议显式返回0
}

// 函数实现：通过指针修改原结构体，返回指针
struct point* getStruct(struct point *p)
{
    scanf("%d", &p->x);   // 读取x值到原结构体
    scanf("%d", &p->y);   // 读取y值到原结构体
    printf("getStruct输出：%d, %d\n", p->x, p->y);  // 加换行符区分输出
    return p;  // 返回原结构体的指针
}

// 按值接收结构体并输出
void output(struct point p)
{
    printf("output输出：%d, %d\n", p.x, p.y);  // 加换行符区分输出
}

// 按const指针接收结构体并输出（保证不修改原数据）
void print(const struct point *p)
{
    printf("print输出：%d, %d\n", p->x, p->y);  // 加换行符区分输出
}