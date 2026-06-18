#include <stdio.h>
#include <stdlib.h>

#define m 13
#define NULLKEY 0

typedef int KeyType; // 假设关键字为整型
typedef struct {
    KeyType key;
} RecordType;

typedef RecordType HashTable[m];

// 哈希函数
int hash(KeyType k);
//8.16 哈希表的查找算法
int HashSearch(HashTable ht, KeyType K);


int main() {
    int n, p, j, hj, k, result;
    HashTable ht;

    // 初始化哈希表
    for (int i = 0; i < m; i++)
        ht[i].key = NULLKEY;

    printf("请输入哈希表的元素个数（不超过 %d 个）: ", m);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 个元素: ", i + 1);
        scanf("%d", &p);

        j = hash(p);
        if (ht[j].key == NULLKEY) {
            ht[j].key = p;
        } else {
            int inserted = 0;
            for (int t = 1; t < m; t++) {
                hj = (j + t) % m;
                if (ht[hj].key == NULLKEY) {
                    ht[hj].key = p;
                    inserted = 1;
                    break;
                }
            }
            if (!inserted) {
                printf("哈希表已满，无法插入元素 %d\n", p);
            }
        }
    }

    // 输出哈希表内容
    printf("\n当前哈希表:\n");
    for (int i = 0; i < m; i++) {
        printf("位置 %2d: ", i);
        if (ht[i].key != NULLKEY)
            printf("%d\n", ht[i].key);
        else
            printf("空\n");
    }

    // 执行查找
    printf("\n请输入要查找的元素: ");
    scanf("%d", &k);
    result = HashSearch(ht, k);
    if (result == -1)
        printf("未找到元素 %d\n", k);
    else
        printf("元素 %d 的位置是 %d\n", k, result);

    return 0;
}

// 哈希函数
int hash(KeyType k) {
    return k % m;
}

//8.16 哈希表的查找算法
int HashSearch(HashTable ht, KeyType K) {
    int h0 = hash(K);
    if (ht[h0].key == NULLKEY) {
        return -1;
    } else if (ht[h0].key == K) {
        return h0;
    } else {
        for (int i = 1; i < m; i++) {
            int hi = (h0 + i) % m;
            if (ht[hi].key == NULLKEY) {
                return -1;
            } else if (ht[hi].key == K) {
                return hi;
            }
        }
        return -1;
    }
}
