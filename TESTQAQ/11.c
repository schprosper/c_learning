/*第三道题是输入一个英文句子，只带英文字母和空格，最后把所有长度为5的单词打印出来。*/
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];  // 存输入的句子（篮子）
    char word[50];        // 存当前拆分的单词
    int word_len = 0;     // 记录单词长度（初始0）

    // 用scanf读整句：%[^\n] 表示“读所有字符，直到按回车为止”（包含空格）
    printf("请输入英文句子（仅字母和空格）：");
    scanf("%[^\n]", sentence);  

    // 遍历句子的每个字符，拆单词
    for (int i = 0; sentence[i] != '\0'; i++) {
        // 不是空格 → 是字母，存到word里，长度+1
        if (sentence[i] != ' ') {
            word[word_len] = sentence[i];
            word_len++;
            word[word_len] = '\0';  // 保证单词能正常打印
        } 
        // 是空格 → 单词结束，检查长度
        else {
            if (word_len == 5) {
                printf("%s\n", word);
            }
            word_len = 0;  // 重置长度，存下一个单词
        }
    }

    // 处理最后一个单词（末尾无空格）
    if (word_len == 5) {
        printf("%s\n", word);
    }

    return 0;
}