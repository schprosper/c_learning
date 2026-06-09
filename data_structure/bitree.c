#include <stdio.h>
#include <stdbool.h>

typedef char Elemtype;

typedef struct TreeNode
{
    Elemtype data;
    struct TreeNode *lchild,*rchild;
}TreeNode;

typedef TreeNode* BiTree;

char str[ ] = "ABDH#K###E##CFI###G#HJ##";
/*K后面有两个空的子节点*/

//前序遍历
void PreOrder(BiTree T){
    //展开逻辑，展开之后拿到的东西，还一样
    if (T == NULL)
    {
        return;
    }
    printf("%c",T->data);
    PreOrder(T->lchild);
    //这里是先后顺序执行，所以先左孩子，后右孩子
    //除非你多线程 
    PreOrder(T->rchild);
    
}

//中序遍历

//后序遍历

//构建二叉树(重要思路)
void creatTree(BiTree *T)
{

};


char main(){

}