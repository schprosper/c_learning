#include <stdio.h>
#include <stdlib.h>


#define MAXLEN 40

typedef struct {
    char ch[MAXLEN];
    int len;
} SString;

/* 遍历*/
void print_string(SString S) {
    for (int i = 0; i < S.len; i++) {
        printf("%c", S.ch[i]);
    }
}
/*字符串反转——左右指针交换*/

void reverse_string(SString *S) {
    int i = 0;
    int j = S->len - 1;
    char temp;

    while (i < j) {
        temp = S->ch[i];
        S->ch[i] = S->ch[j];
        S->ch[j] = temp;

        i++;
        j--;
    }
}
#include <stdbool.h>
/*求子串*/
bool substring(SString S, int pos, int len, SString *Sub) {
    if (pos < 0 || len < 0 || pos + len > S.len) {
        return false;
    }

    for (int i = 0; i < len; i++) {
        Sub->ch[i] = S.ch[pos + i];
    }

    Sub->len = len;
    return true;
}

/*字符串比较：知道字典序*/
int compare_string(SString S, SString T) {
    int i = 0;

    while (i < S.len && i < T.len) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
        i++;
    }

    return S.len - T.len;
}
/*从前往后比。
谁先出现不同字符，就按字符大小判断。
前面都相同，则短串更小。*/



