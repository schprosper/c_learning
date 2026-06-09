/* 知识点：
1. 函数定义：含多参数（int变量、int数组、int变量）的函数原型与实现；
2. 循环结构：遍历[low, high]范围、遍历数组a的循环；
3. 条件判断：判断数字能否被数组所有元素整除、异常情况（high<low、数组空指针）；
4. 逻辑运算：结合循环与条件，实现“被所有元素整除”的逻辑；
5. 数组操作：数组作为函数参数的传递与元素访问。
*/


// 题目：编写一个函数
// 函数原型：int num(int low, int high, int a[], int n);
// 说明：
// - low：被除数的最小值；high：被除数的最大值；
// - n：数组a的元素个数；
// - 功能：统计[low, high]中能被数组a所有元素整除的数字个数；
// 示例：
// 当low=1、high=100、n=2、a[0]=2、a[1]=3时，返回16；
// 异常处理：
// - 若high<low，或a是空指针，输出"error"。

#include <stdio.h>

// 函数原型：题目指定
int num(int low, int high, int a[], int n);

// 函数实现
int num(int low, int high, int a[], int n) {
    // 异常处理1：high < low 或 数组a是空指针（NULL）
    if (high < low || a == NULL) {
        printf("error\n");
        return 0; // 异常时返回0（无符合条件的数）
    }

    int count = 0; // 统计符合条件的数字个数
    // 步骤1：遍历[low, high]范围内的每一个数字i
    for (int i = low; i <= high; i++) {
        int is_valid = 1; // 标记：i是否能被数组所有元素整除（初始为“是”）
        // 步骤2：遍历数组a的所有元素，检查i是否能被每个元素整除
        for (int j = 0; j < n; j++) {
            // 若i不能被a[j]整除，标记为“否”，并跳出数组遍历
            if (i % a[j] != 0) {
                is_valid = 0;
                break;
            }
        }
        // 步骤3：如果i能被所有元素整除，计数+1
        if (is_valid == 1) {
            count++;
        }
    }

    return count; // 返回最终统计结果
}

// 测试用例（验证示例）
int main() {
    int a[] = {2, 3}; // 示例数组
    int n = 2;        // 数组元素个数
    int low = 1, high = 100;
    
    // 调用函数并输出结果
    int result = num(low, high, a, n);
    if (result != 0 || (high >= low && a != NULL)) { // 异常时已输出error，这里只输出正常结果
        printf("符合条件的数字个数：%d\n", result); // 输出16，和示例一致
    }

    // 测试异常场景（比如high < low）
    // num(10, 5, a, n); // 会输出error

    return 0;
}