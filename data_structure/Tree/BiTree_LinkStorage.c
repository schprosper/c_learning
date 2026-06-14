#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct TreeNode
{
    ElemType data ;
    struct TreeNode* lchild ;
    struct TreeNode* rchild ;

}TreeNode;

//这里传入的其实是指向树根的指针。
typedef TreeNode* BiTree;


/*递归的方式遍历二叉树——前序遍历*/
void preOrder(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    printf("%c",T->data);
    preOrder(T->lchild);
    preOrder(T->rchild);
}

/*中序遍历*/
void inOrder(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    
    preOrder(T->lchild);
    preOrder(T->rchild);
    printf("%c",T->data);
}

void postOrder(BiTree T)
{
    if(T == NULL)
    {
        return;
    }
    
    preOrder(T->lchild);
    preOrder(T->rchild);
    printf("%c",T->data);
}


char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;
/*创建二叉树*/
void createTree(BiTree *T)
{
    ElemType ch;
    ch = str[idx++];
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&(*T)->lchild);
        createTree(&(*T)->rchild);
    }
}





int main(int argc, char const *argv[])
{
    BiTree T;
    createTree(&T);

    preOrder(T);
    printf("\n");

    inOrder(T);
    printf("\n");

    postOrder(T);
    printf("\n");

    return 0;
}