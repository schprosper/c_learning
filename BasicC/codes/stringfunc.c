#include <stdio.h>
#include <string.h>  // 包含 strlen 函数的头文件
int mylen(const char *s)
{

    int idx = 0;
    while(s[idx]!='\0')
    {
        idx++;
    }
    return idx;


}
int main() {
    // 定义一个以 '\0' 结尾的 C 字符串
    char str1[] = "Hello";
    char str2[] = "豆包，你好！";  // 中文字符串（注意：一个中文字符在 UTF-8 中占多字节，但 strlen 按字节计数）
    
    // 计算字符串长度
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    
    // 输出结果
    printf("字符串 \"%s\" 的长度是：%zu（不包含结尾的\\0）\n", str1, len1);
    printf("字符串 \"%s\" 的长度是：%zu（按字节计数）\n", str2, len2);
    
    return 0;
}