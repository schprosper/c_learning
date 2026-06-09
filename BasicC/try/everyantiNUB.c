#include <stdio.h>

int main() {
    long long num, reversed = 0;  // 用long long避免大数字溢出
    int sign = 1;  // 记录符号（1为正，-1为负）

    printf("请输入一个整数：");
    scanf("%lld", &num);  // 读取任意整数（支持long long范围）

    // 处理负数：记录符号后转为正数处理
    if (num < 0) {
        sign = -1;
        num = -num;  // 取绝对值
    }

    // 循环提取最后一位，构建反转后的数字
    while (num != 0) {
        int last_digit = num % 10;  // 提取最后一位（如1234%10=4）
        reversed = reversed * 10 + last_digit;  // 拼接最后一位（如0*10+4=4 → 4*10+3=43...）
        num = num / 10;  // 去掉最后一位（如1234/10=123）
    }

    // 恢复符号
    reversed *= sign;

    printf("反转后的数字是：%lld\n", reversed);

    return 0;
}