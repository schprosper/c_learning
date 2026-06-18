#include <stdio.h>
#include <stdlib.h>

#define ENDKEY 0

typedef int KeyType;

typedef struct node {
    KeyType key;
    struct node *lchild, *rchild;
} BSTNode, *BSTree;

//8.4 二叉排序树查找的递归算法
BSTree SearchBST1(BSTree bst, KeyType key);
//8.5 二叉排序树查找的非递归算法
BSTree SearchBST2(BSTree bst, KeyType key);
//8.6 二叉排序树插入的递归算法
void InsertBST1(BSTree *bst, KeyType key);
//8.7 二叉排序树插入的非递归算法
void InsertBST2(BSTree *bst, KeyType key);
//8.8 创建二叉排序树
void CreateBST(BSTree *bst, int useInsert1);
// 先序遍历BST
void PreOrder(BSTree root);


// 主函数
int main(void) {
    BSTree T;
    int k;
    BSTree result1, result2;

    int useInsert1 = 1;  // 设为1使用8.6 InsertBST1（递归），设为0使用8.7 InsertBST2（非递归）
    CreateBST(&T, useInsert1); //8.8

    printf("先序遍历输出序列为：");
    PreOrder(T);
    printf("\n");

    printf("请输入要查找的元素：");
    scanf(" %d", &k);

    result1 = SearchBST1(T, k);
    if (result1 != NULL) {
        printf("8.4 SearchBST1：查找成功，元素为 %d\n", result1->key);
        printf("8.4 SearchBST1：该节点为根的子树先序遍历为：");
        PreOrder(result1);
        printf("\n");
    } else {
        printf("8.4 SearchBST1：未找到！\n");
    }

    result2 = SearchBST2(T, k);
    if (result2 != NULL) {
        printf("8.5 SearchBST2：查找成功，元素为 %d\n", result2->key);
        printf("8.5 SearchBST2：该节点为根的子树先序遍历为：");
        PreOrder(result2);
        printf("\n");
    } else {
        printf("8.5 SearchBST2：未找到！\n");
    }

    return 0;
}

//8.4 二叉排序树查找的递归算法
BSTree SearchBST1(BSTree bst, KeyType key) {
    if (!bst)
        return NULL;
    else if (bst->key == key)
        return bst;
    else if (key < bst->key)
        return SearchBST1(bst->lchild, key);
    else
        return SearchBST1(bst->rchild, key);
}

//8.5 二叉排序树查找的非递归算法
BSTree SearchBST2(BSTree bst, KeyType key) {
    while (bst) {
        if (bst->key == key)
            return bst;
        else if (key < bst->key)
            bst = bst->lchild;
        else
            bst = bst->rchild;
    }
    return NULL;
}

//8.6 二叉排序树插入的递归算法
void InsertBST1(BSTree *bst, KeyType key) {
    if (*bst == NULL) {
        BSTree s = (BSTree)malloc(sizeof(BSTNode));
        if (!s) {
            printf("内存分配失败！\n");
            exit(1);
        }
        s->key = key;
        s->lchild = s->rchild = NULL;
        *bst = s;
    } else if (key < (*bst)->key) {
        InsertBST1(&((*bst)->lchild), key);
    } else if (key > (*bst)->key) {
        InsertBST1(&((*bst)->rchild), key);
    }
}

//8.7 二叉排序树插入的非递归算法
void InsertBST2(BSTree *bst, KeyType key) {
    BSTree p = *bst, parent = NULL;

    while (p != NULL) {
        if (key == p->key) {
            return;  // 不插入重复元素
        }
        parent = p;
        if (key < p->key)
            p = p->lchild;
        else
            p = p->rchild;
    }

    BSTree s = (BSTree)malloc(sizeof(BSTNode));
    if (!s) {
        printf("内存分配失败！\n");
        exit(1);
    }
    s->key = key;
    s->lchild = s->rchild = NULL;

    if (parent == NULL) {
        *bst = s;
    } else if (key < parent->key) {
        parent->lchild = s;
    } else {
        parent->rchild = s;
    }
}

//8.8 创建二叉排序树
void CreateBST(BSTree *bst, int useInsert1) {
    KeyType key;
    *bst = NULL;
    printf("请输入整数序列（以0结束）：\n");
    scanf("%d", &key);
    while (key != ENDKEY) {
        if (useInsert1)
            InsertBST1(bst, key);
        else
            InsertBST2(bst, key);
        scanf("%d", &key);
    }
}

// 先序遍历BST
void PreOrder(BSTree root) {
    if (root != NULL) {
        printf("%d  ", root->key);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}
