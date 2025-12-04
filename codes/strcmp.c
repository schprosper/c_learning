#include <stdio.h>
#include <string.h>

int main() {
    // 情况1：s1 与 s2 完全相等
    char s1[] = "Hello";
    char s2[] = "Hello";
    int result1 = strcmp(s1, s2);
    printf("strcmp(\"%s\", \"%s\") = %d （表示 s1 == s2）\n", s1, s2, result1);

    // 情况2：s1 大于 s2（按ASCII码比较，'W'的ASCII值大于'H'）
    char s3[] = "World";
    char s4[] = "Hello";
    int result2 = strcmp(s3, s4);
    printf("strcmp(\"%s\", \"%s\") = %d （表示 s1 > s2）\n", s3, s4, result2);

    // 情况3：s1 小于 s2（'A'的ASCII值小于'B'）
    char s5[] = "Apple";
    char s6[] = "Banana";
    int result3 = strcmp(s5, s6);
    printf("strcmp(\"%s\", \"%s\") = %d （表示 s1 < s2）\n", s5, s6, result3);

    
    return 0;
}