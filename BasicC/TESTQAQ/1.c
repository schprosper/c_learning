#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char input[101];   // 存输入字符串
    char result[101];  // 存处理后的字符串
    int length;        // 输入字符串实际长度（去回车符）
    int res_idx = 0;   // 结果数组下标
    int is_valid = 1;  // 合法性标记
    int first_alpha = -1;  // 第一个字母的位置（初始-1表示未找到）
    int last_alpha = -1;   // 最后一个字母的位置（初始-1表示未找到）

    // 1. 读取输入 + 去回车符
    printf("请输入字符串（长度<100）：");
    fgets(input, sizeof(input), stdin);
    length = strlen(input) - 1;
    input[length] = '\0';  // 真正删除回车符

    // 2. 长度校验
    if (length >= 100) {
        printf("error\n");
        return 1;
    }

    for (int i =0;i<length;i++)
    {
        char ch = input[i];
        if (ch != '*' && !isalpha(ch))
        {
            is_valid = 0;
            printf("error\n");
            return 1;
        }

        if(isalpha(ch)&&first_alpha == -1)
        {
            first_alpha = i;
        }

        if(isalpha(ch))
        {
            last_alpha = i;
        }

    }

    for(int i =0;i<length;i++)
    {
        char ch;
        ch = input[i];

        if (ch !='*')
        {
            result[res_idx] = input[i];
            res_idx ++;
        }

        else
        {

            if(i<first_alpha || i>last_alpha)
            {
                result[res_idx] = '*';
                res_idx ++;
            }
        }
    }

    result[res_idx] ='\0';

    printf("%s\n", result);



}