#include <stdio.h>

int main() {
    int ch;
    // 循环读取字符，直到遇到EOF（文件结束符）
    while ((ch = getchar()) != EOF) {
        // 输出读取到的字符
        putchar(ch);
    }
    printf("%p",&ch);
    printf("EPF");
        return 0;
}
// ctrl c 强制结束
//ctrl z  输入EOF
