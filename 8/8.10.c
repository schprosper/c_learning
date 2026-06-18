#include <stdio.h>
#include <stdlib.h>

#define ENDKEY 0

typedef int KeyType;

typedef struct node {
    KeyType key; // 关键字的值
    int bf;      // 平衡因子
    struct node *lchild, *rchild; // 左右子树
} AVLTNode, *AVLTree;

// AVL树的插入算法
void ins_AVLtree(AVLTree *avlt, KeyType K);
// AVL树的查找算法
void CreateAVLT(AVLTree *bst);
// 先序遍历AVL树
void PreOrder(AVLTree root);


int main(void) {
    AVLTree T;
    printf("建立平衡二叉排序树，请输入序列（以0结束）：\n");
    CreateAVLT(&T);
    printf("先序遍历输出序列为:\n");
    PreOrder(T);
    printf("\n");
    return 0;
}

// AVL树的插入算法
void ins_AVLtree(AVLTree *avlt, KeyType K) {
    AVLTNode *S = (AVLTNode *)malloc(sizeof(AVLTNode));
    S->key = K;
    S->lchild = S->rchild = NULL;
    S->bf = 0;

    if (*avlt == NULL) {
        *avlt = S;
        return;
    }

    AVLTree A = *avlt, FA = NULL, p = *avlt, fp = NULL;
    while (p != NULL) {
        if (p->bf != 0) {
            A = p;
            FA = fp;
        }
        fp = p;
        if (K < p->key)
            p = p->lchild;
        else
            p = p->rchild;
    }

    if (K < fp->key)
        fp->lchild = S;
    else
        fp->rchild = S;

    AVLTree B, C;
    if (K < A->key) {
        B = A->lchild;
        A->bf++;
    } else {
        B = A->rchild;
        A->bf--;
    }

    p = B;
    while (p != S) {
        if (K < p->key) {
            p->bf = 1;
            p = p->lchild;
        } else {
            p->bf = -1;
            p = p->rchild;
        }
    }

    if (A->bf == 2 && B->bf == 1) { // LL型
        A->lchild = B->rchild;
        B->rchild = A;
        A->bf = B->bf = 0;
        if (FA == NULL)
            *avlt = B;
        else if (FA->lchild == A)
            FA->lchild = B;
        else
            FA->rchild = B;
    } else if (A->bf == 2 && B->bf == -1) { // LR型
        C = B->rchild;
        B->rchild = C->lchild;
        A->lchild = C->rchild;
        C->lchild = B;
        C->rchild = A;

        if (S->key < C->key) {
            A->bf = -1;
            B->bf = 0;
        } else if (S->key > C->key) {
            A->bf = 0;
            B->bf = 1;
        } else {
            A->bf = B->bf = 0;
        }
        C->bf = 0;

        if (FA == NULL)
            *avlt = C;
        else if (FA->lchild == A)
            FA->lchild = C;
        else
            FA->rchild = C;
    } else if (A->bf == -2 && B->bf == 1) { // RL型
        C = B->lchild;
        B->lchild = C->rchild;
        A->rchild = C->lchild;
        C->lchild = A;
        C->rchild = B;

        if (S->key < C->key) {
            A->bf = 0;
            B->bf = -1;
        } else if (S->key > C->key) {
            A->bf = 1;
            B->bf = 0;
        } else {
            A->bf = B->bf = 0;
        }
        C->bf = 0;

        if (FA == NULL)
            *avlt = C;
        else if (FA->lchild == A)
            FA->lchild = C;
        else
            FA->rchild = C;
    } else if (A->bf == -2 && B->bf == -1) { // RR型
        A->rchild = B->lchild;
        B->lchild = A;
        A->bf = B->bf = 0;
        if (FA == NULL)
            *avlt = B;
        else if (FA->lchild == A)
            FA->lchild = B;
        else
            FA->rchild = B;
    }
}

// AVL树的查找算法
void CreateAVLT(AVLTree *bst) {
    KeyType key;
    *bst = NULL;
    scanf("%d", &key);
    while (key != ENDKEY) {
        ins_AVLtree(bst, key);
        scanf("%d", &key);
    }
}
// 先序遍历AVL树
void PreOrder(AVLTree root) {
    if (root != NULL) {
        printf("%d  ", root->key);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}