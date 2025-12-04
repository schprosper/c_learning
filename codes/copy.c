#include <stdio.h>
#include <string.h>  // 包含 strcpy 函数的头文件

int main() {
    // 1. 定义源字符串（src）和目标字符串（dst）
    char src[] = "Hello, 豆包!";  // 源字符串，包含结尾的 '\0'
    char dst[20];  // 目标数组，需确保空间足够容纳 src（包括 '\0'）

    // 2. 使用 strcpy 复制字符串：将 src 内容复制到 dst
    char* result = strcpy(dst, src);

    // 3. 输出结果
    printf("源字符串 src: %s\n", src);
    printf("复制后 dst: %s\n", dst);
    printf("strcpy 返回值: %s（与 dst 相同，因为返回目标地址）\n", result);

    // 4. 链式调用示例（利用返回值为 dst 的特性）
    printf("链式使用：%s\n", strcpy(dst, "链式调用测试"));

    return 0;
}