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
    RecordType r[LIST_SIZE + 1];  // r[0] unused
    int length;
} RecordList;

// 清除输入缓冲区
void clearInputBuffer();
// 创建线性表
void createlist(RecordList *l);
//8.3 折半查找法
int BinSrch(RecordList l, KeyType k);


int main() {
    RecordList l;
    int locate;
    KeyType k;

    createlist(&l);

    printf("请输入要查找的元素: ");
    scanf(" %c", &k);  // 空格跳过回车

    locate = BinSrch(l, k);
    if (locate == 0)
        printf("未找到!\n");
    else
        printf("该元素在表中的位置为 %d\n", locate);

    return 0;
}

// 清除输入缓冲区
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// 创建线性表
void createlist(RecordList *l) {
    int i, len;
    KeyType ch;

    printf("请输入线性表的长度: ");
    scanf("%d", &len);
    clearInputBuffer(); // 清除输入残留

    l->length = len;
    for (i = 1; i <= len; i++) {
        printf("请输入线性表的第%d个元素: ", i);
        scanf(" %c", &ch);  // 空格跳过空白字符
        l->r[i].key = ch;
    }
}

//8.3 折半查找法
int BinSrch(RecordList l, KeyType k) {
    int low = 1, high = l.length, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (k == l.r[mid].key)
            return mid;
        else if (k < l.r[mid].key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}