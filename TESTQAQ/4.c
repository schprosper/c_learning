/* 知识点：
1. 字符串处理：C语言字符串的遍历、字符修改（删除指定字符）；
2. 字符判断：区分'*'、字母（大小写）与其他非法字符；
3. 错误处理：含非法字符时输出"error"；
4. 长度限制：处理长度<100的字符串；
5. 标准I/O：读取输入字符串、输出处理后字符串。
*/
// 题目：字符串的处理和输出
// 要求：
// 1. 接受长度<100的字符串；
// 2. 字符串只能含'*'和字母，含其他字符则输出"error"；
// 3. 删除字母之间的'*'，输出处理后的字符串；
// 样例：
// 输入：****A*B*CDe*f*****
// 输出：****ABCDef*****


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

    // 3. 合法性校验 + 找第一个/最后一个字母的位置
    for (int i = 0; i < length; i++) {
        // 非法字符判断
        if (input[i] != '*' && !isalpha(input[i])) {
            is_valid = 0;
            break;
        }
        // 记录第一个字母的位置（只记一次）
        if (isalpha(input[i]) && first_alpha == -1) {
            first_alpha = i;
        }
        // 记录最后一个字母的位置（一直更新）
        if (isalpha(input[i])) {
            last_alpha = i;
        }
    }
    if (!is_valid) {
        printf("error\n");
        return 1;
    }

    // 4. 处理字符串：删除字母区间内的所有*
    for (int i = 0; i < length; i++) {
        // 情况1：当前字符不是* → 直接保留
        if (input[i] != '*') {
            result[res_idx++] = input[i];
        }
        // 情况2：当前字符是* → 判断是否在字母区间外（开头/结尾）
        else {
            // 字母区间外的* → 保留；区间内的* → 删除
            if (i < first_alpha || i > last_alpha) {
                result[res_idx++] = '*';
            }
        }
    }
    result[res_idx] = '\0';  // 结束符

    // 5. 输出结果
    printf("%s\n", result);

    return 0;
}