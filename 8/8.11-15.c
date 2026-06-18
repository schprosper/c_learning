#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 3
typedef int Boolean;
typedef int KeyType;
#define TRUE 1
#define FALSE 0

typedef struct Mbtnode {
    struct Mbtnode *parent;
    int keynum;
    KeyType key[M + 1];
    struct Mbtnode *ptr[M + 1];
} Mbtnode, *Mbtree;

//8.14 在B树的指定位置插上key
void insert(Mbtree mbp, int ipos, KeyType key, Mbtree rp);
//8.15 B树的分裂算法
void split(Mbtree oldp, Mbtree *newp);
//8.12 在B树种寻找小于等于关键字k的关键字序号
int search(Mbtree mbt, KeyType key);
//8.13 B树的插入算法
void ins_mbtree(Mbtree *mbt, KeyType k, Mbtree q, int i);
//8.11 在B树种查找关键字为k的元素
Boolean srch_mbtree(Mbtree mbt, KeyType k, Mbtree *np, int *pos);
// 创建B树
void Creatembtree(Mbtree *mbt);
// B树的先序遍历
void PreOrderPrint(Mbtree t, int level);



int main(void) {
    Mbtree bt = NULL;
    Creatembtree(&bt);
    printf("\n创建成功，B树先序遍历如下：\n");
    PreOrderPrint(bt, 0);
    return 0;
}

//8.14 在B树的指定位置插上key
void insert(Mbtree mbp, int ipos, KeyType key, Mbtree rp) {
    int j;
    for (j = mbp->keynum; j >= ipos + 1; j--) {
        mbp->key[j + 1] = mbp->key[j];
        mbp->ptr[j + 1] = mbp->ptr[j];
    }
    mbp->key[ipos + 1] = key;
    mbp->ptr[ipos + 1] = rp;
    if (rp != NULL)
        rp->parent = mbp;
    mbp->keynum++;
}

//8.15 B树的分裂算法
void split(Mbtree oldp, Mbtree *newp) {
    int s = ceil((float)M / 2); // s = 2
    int n = M - s;              // n = 1
    *newp = (Mbtree)malloc(sizeof(Mbtnode));
    (*newp)->keynum = n;
    (*newp)->parent = oldp->parent;

    for (int i = 0; i <= n; i++)
        (*newp)->ptr[i] = NULL;

    for (int i = 1; i <= n; i++) {
        (*newp)->key[i] = oldp->key[s + i];
        (*newp)->ptr[i] = oldp->ptr[s + i];
        if ((*newp)->ptr[i] != NULL)
            (*newp)->ptr[i]->parent = *newp;
    }
    (*newp)->ptr[0] = oldp->ptr[s];
    if ((*newp)->ptr[0] != NULL)
        (*newp)->ptr[0]->parent = *newp;

    oldp->keynum = s - 1;
}

//8.12 在B树种寻找小于等于关键字k的关键字序号
int search(Mbtree mbt, KeyType key) {
    int i = 1;
    while (i <= mbt->keynum && mbt->key[i] <= key)
        i++;
    return i - 1;
}

//8.13 B树的插入算法
void ins_mbtree(Mbtree *mbt, KeyType k, Mbtree q, int i) {
    Mbtree ap = NULL, q1 = NULL, new_root;
    KeyType x = k;
    int s, finished = FALSE;

    if (*mbt == NULL) {
        *mbt = (Mbtree)malloc(sizeof(Mbtnode));
        (*mbt)->keynum = 1;
        (*mbt)->parent = NULL;
        (*mbt)->key[1] = k;
        for (int i = 0; i <= M; i++)
            (*mbt)->ptr[i] = NULL;
        return;
    }

    while (q != NULL && !finished) {
        insert(q, i, x, ap);
        if (q->keynum < M)
            finished = TRUE;
        else {
            s = ceil((float)M / 2);
            split(q, &q1);
            x = q->key[s];
            ap = q1;
            q = q->parent;
            if (q != NULL)
                i = search(q, x);
        }
    }

    if (!finished) {
        new_root = (Mbtree)malloc(sizeof(Mbtnode));
        new_root->keynum = 1;
        new_root->parent = NULL;
        new_root->key[1] = x;
        new_root->ptr[0] = *mbt;
        new_root->ptr[1] = ap;
        *mbt = new_root;
        (*mbt)->ptr[0]->parent = *mbt;
        (*mbt)->ptr[1]->parent = *mbt;
    }
}

//8.11 在B树种查找关键字为k的元素
Boolean srch_mbtree(Mbtree mbt, KeyType k, Mbtree *np, int *pos) {
    Mbtree p = mbt, fp = NULL;
    Boolean found = FALSE;
    int i = 0;

    while (p != NULL && !found) {
        i = search(p, k);
        if (i > 0 && p->key[i] == k)
            found = TRUE;
        else {
            fp = p;
            p = p->ptr[i];
        }
    }

    if (found) {
        *np = p;
        *pos = i;
        return TRUE;
    } else {
        *np = fp;
        *pos = i;
        return FALSE;
    }
}
// 创建B树
void Creatembtree(Mbtree *mbt) {
    int k;
    Mbtree q = NULL;
    int i = 0;
    *mbt = NULL;

    printf("请输入一个元素（以0结束）：");
    while (scanf("%d", &k) && k != 0) {
        Mbtree np;
        int pos;
        if (!srch_mbtree(*mbt, k, &np, &pos))
            ins_mbtree(mbt, k, np, pos);
        printf("继续输入元素（以0结束）：");
    }
}
// B树的先序遍历
void PreOrderPrint(Mbtree t, int level) {
    if (t != NULL) {
        printf("Level %d: ", level);
        for (int i = 1; i <= t->keynum; i++)
            printf("%d ", t->key[i]);
        printf("\n");
        for (int i = 0; i <= t->keynum; i++)
            PreOrderPrint(t->ptr[i], level + 1);
    }
}