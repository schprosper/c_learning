#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct node {
    KeyType key;
    struct node *lchild, *rchild;
} BSTNode, *BSTree;

//8.9 在二叉排序树中删除结点
BSTree DelBST(BSTree t, KeyType k);
// 用于验证删除结果：中序遍历（会按升序打印）
void InOrder(BSTree root);


int main() {
    // 手动构造如下BST:
    //        50
    //       /  \
    //     30    70
    //    / \    / \
    //   20 40  60 80

    BSTree root = (BSTree)malloc(sizeof(BSTNode));
    root->key = 50;
    root->lchild = (BSTree)malloc(sizeof(BSTNode));
    root->rchild = (BSTree)malloc(sizeof(BSTNode));

    root->lchild->key = 30;
    root->lchild->lchild = (BSTree)malloc(sizeof(BSTNode));
    root->lchild->rchild = (BSTree)malloc(sizeof(BSTNode));
    root->lchild->lchild->key = 20;
    root->lchild->lchild->lchild = root->lchild->lchild->rchild = NULL;
    root->lchild->rchild->key = 40;
    root->lchild->rchild->lchild = root->lchild->rchild->rchild = NULL;

    root->rchild->key = 70;
    root->rchild->lchild = (BSTree)malloc(sizeof(BSTNode));
    root->rchild->rchild = (BSTree)malloc(sizeof(BSTNode));
    root->rchild->lchild->key = 60;
    root->rchild->lchild->lchild = root->rchild->lchild->rchild = NULL;
    root->rchild->rchild->key = 80;
    root->rchild->rchild->lchild = root->rchild->rchild->rchild = NULL;

    printf("原始中序遍历结果：\n");
    InOrder(root);

    int delKey;
    printf("\n请输入要删除的结点值：");
    scanf("%d", &delKey);

    root = DelBST(root, delKey);

    printf("删除后中序遍历结果：\n");
    InOrder(root);
    printf("\n");

    return 0;
}

//8.9 在二叉排序树中删除结点
BSTree DelBST(BSTree t, KeyType k) {
    BSTNode *p = t, *f = NULL, *s, *q;

    while (p) {
        if (p->key == k) break;
        f = p;
        if (p->key > k)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (!p) return t;

    if (!p->lchild) {
        if (!f)
            t = p->rchild;
        else if (f->lchild == p)
            f->lchild = p->rchild;
        else
            f->rchild = p->rchild;
        free(p);
    } else {
        q = p;
        s = p->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }
        if (q == p)
            q->lchild = s->lchild;
        else
            q->rchild = s->lchild;
        p->key = s->key;
        free(s);
    }
    return t;
}

// 用于验证删除结果：中序遍历（会按升序打印）
void InOrder(BSTree root) {
    if (root) {
        InOrder(root->lchild);
        printf("%d ", root->key);
        InOrder(root->rchild);
    }
}

