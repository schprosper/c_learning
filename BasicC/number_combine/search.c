//在给定的数据中如何找出某个数据是否存在？
#include <stdio.h>

/**
 * 找出 key 在数组 a 中的位置
 * @param key 要寻找的数字
 * @param a 要寻找的数组
 * @param length 数组的长度
 * @return 如果找到，返回其在数组中的索引；如果找不到则返回 -1
 */
int search(int key, int a[], int length);

int main(void)
{
    // 定义并初始化数组
    int a[] = {2, 4, 6, 7, 1, 3, 5, 9, 11, 13, 23, 14, 32};
    int x;
    int loc;

    printf("请输入一个数字: ");
    scanf("%d", &x);

    // 调用 search 函数，sizeof(a)/sizeof(a[0]) 计算数组长度
    loc = search(x, a, sizeof(a) / sizeof(a[0]));//是这么写，但是sizeof需要用别的来承接

    if (loc != -1) {
        // 注意：数组索引从 0 开始，若要显示“第 N 个位置”，需 loc+1
        printf("%d 在第 %d 个位置上\n", x, loc + 1);
    } else {
        printf("%d 不存在\n", x);
    }

    return 0;
}

// 实现 search 函数（线性查找）
int search(int key, int a[], int length)
{
    int ret = -1; // 初始化为 -1，表示未找到
    for (int i = 0; i < length; i++) {
        if (a[i] == key) {
            ret = i; // 找到目标值，记录索引
            break;   // 找到后立即退出循环
        }
    }
    return ret;
}