#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 20

typedef char KeyType;
typedef int OtherType;

typedef struct {
    KeyType key;
    OtherType other_data;
} RecordType;

typedef struct {
    RecordType r[LIST_SIZE + 1]; // r[0] 为哨兵
    int length;
} RecordList;

// 清除输入缓冲区
void clearInputBuffer();
// 创建线性表
void createlist(RecordList *l);
//8.1 设置监视哨的顺序查找法
int SeqSearch(RecordList l, KeyType k);
//8.2 不设置监视哨的顺序查找法
int SeqSearch2(RecordList l, KeyType k);    


int main() {
    RecordList l;
    int locate1, locate2;
    KeyType k;

    createlist(&l);

    printf("请输入要查找的元素: ");
    scanf(" %c", &k); // 跳过空格或换行符

    locate1 = SeqSearch(l, k);
    if (locate1 == 0)
        printf("8.1 SeqSearch: 未找到!\n");
    else
        printf("8.1 SeqSearch: 该元素在表中的位置为 %d\n", locate1);

    locate2 = SeqSearch2(l, k);
    if (locate2 == 0)
        printf("8.2 SeqSearch2: 未找到!\n");
    else
        printf("8.2 SeqSearch2: 该元素在表中的位置为 %d\n", locate2);

    return 0;
}

// 清除输入缓冲区
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // 清除缓冲区
}

// 创建线性表
void createlist(RecordList *l) {
    int i;
    int len;
    KeyType ch;
    printf("请输入线性表的长度: ");
    scanf("%d", &len);
    clearInputBuffer(); // 清空换行符
    l->length = len;

    for (i = 1; i <= len; i++) {
        printf("请输入线性表的第%d个元素: ", i);
        scanf(" %c", &ch); // 前面的空格跳过空白符
        l->r[i].key = ch;
    }
}

//8.1 设置监视哨的顺序查找法
int SeqSearch(RecordList l, KeyType k) {
    int i;
    l.r[0].key = k; // 哨兵
    i = l.length;
    while (l.r[i].key != k) i--;
    return i;
}

//8.2 不设置监视哨的顺序查找法
int SeqSearch2(RecordList l, KeyType k) {
    int i = l.length;
    while (i >= 1 && l.r[i].key != k) i--;
    return (i >= 1) ? i : 0;
}
