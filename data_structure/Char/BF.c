#include <stdio.h>
#include <stdlib.h>


#define MAXLEN 40

typedef struct {
    char ch[MAXLEN];
    int len;
} SString;


int StrIndex(SString S, int pos, SString T) {
    int i, j;

    if (T.len == 0) {
        return 0;
    }

    i = pos; 
    //pos 表示从主串 S 的哪个下标位置开始查找子串 T。
    j = 0;

    while (i < S.len && j < T.len) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j >= T.len) {
        return i - j;
    } else {
        return -1;
    }
}

int index_BF(SString S, SString T) {
    if (T.len == 0) {
        return 0;
    }
    //真正开始干活
    //i是放在主串的那个变量，既然是数组，那么注意，下标从0开始
    for (int i = 0; i <= S.len - T.len; i++) {
        int j = 0;

        while (j < T.len && S.ch[i + j] == T.ch[j])//这里访问顺序不能变
        //是顺序访问的，如果防止越界
        {
            j++;// 这里巧妙的用j代表了lenth。
        }

        if (j == T.len) {
            return i;
        }
    }

    return -1;
}

int index_BF(SString S, SString T)
{
    if(T.len == 0)
    {
        return 0;
    }

    for(int i =0; i<= S.len - T.len;i++)
    {
        int j =0;
        while(T.ch[j] == S.ch[i+j] && j< T.len)
        {
            j++;
        }

        if (j == T.len)
        {
            return i;
        }
        
    }
    return -1;
}
