# include<stdio.h>
# include<string.h>
#include <stdlib.h>
void main()
{
    char string[8];
    scanf("%9s",string);
    //scanf 读入的是一个单词，超过了不读了
    //除非进行%9s这样的限制



    char a[][10] = {"hello"};
    char *b[] = {};

    char str[] = "hello";
    int i = 0;
    while (str[i] !='\0')
    {
        putchar(str[i]);
        //所以putchar 只能读一个字母！！！
        i ++;
    }

    printf("字符串长度：%zu\n", strlen(str)); 
    // 输出5（只算到'o'，不算'\0'）
    //这里和 sizeof 一样的%zu

    printf("abc vs abd：%d\n", strcmp("abc", "abd")); 
        // 输出负数（'c' < 'd'）是第一个不同的字符的——ASC码相减的关系—— 前面-后面
    printf("123 vs 123：%d\n", strcmp("123", "123")); 
        // 输出0（相等）
    printf("xyz vs xya：%d\n", strcmp("xyz", "xya")); 
        // 输出正数（'z' > 'a'）

    // char dest[20]; // 目标数组要足够大
    // char src[] = "world";
    // strcpy(dest, src); // 把src的"world"复制到dest



    // printf("复制后：%s\n", dest); // 输出world


    char dest[20];
    
    char src[] = "hello";
    char *dst =(char*) malloc(strlen(src) + 1);
    strcpy(dst,src);
    printf("复制后：%s\n", dest);
    free(dst);
    




}
