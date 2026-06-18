#include <stdio.h>
#include <stdlib.h>
//==================二叉树定义====================
typedef char ElemType;

typedef struct TreeNode
{
    ElemType data ;
    struct TreeNode* lchild ;
    struct TreeNode* rchild ;

}TreeNode;

//这里传入的其实是指向树根的指针。
typedef TreeNode* BiTree;

//====================动态内存分配栈定义==============================
typedef BiTree ElemType_Stack;

typedef struct Stack
{
    ElemType_Stack data;
    struct Stack* next;
}Stack;

/*空栈*/
int isEmpty(Stack *s)
{
    if (s->next == NULL)
    {
        printf("空的\n");
        return 1;
    }
    else
    {
        return 0;
    }
}


/*初始化*/
Stack* initStack()
{
    Stack* S = (Stack*)malloc(sizeof(Stack));
    S->data = 0;
    S->next = NULL;

    return S;
}

/*进栈*/
int push(Stack* S, ElemType_Stack e)
{
    Stack* p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = S->next;
    S->next = p;
    return 1;
}

int pop(Stack* S, ElemType_Stack *e)
{
    Stack * temp = S->next;
    *e = temp->data;
    S->next = temp->next;
    free(temp);
    return 1 ;
}


// ===================二叉树相关函数============

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

/*非递归前序遍历，想想老师画的栈的图，
思考一下，何时主动入栈和出栈即可*/
void iterPreOrder(Stack *s, BiTree T)
{
    while (T!=NULL|| isEmpty(s) !=0)
    {
        while (T != NULL)
        {
            printf("%c ", T->data);  // 先访问当前节点
            push(s, T);              // 保存当前节点，因为以后还要回来找它的右子树
            T = T->lchild;           // 一直往左走
        }
        pop(s, &T);                  // 左边走到底了，回到上一个节点
        T = T->rchild;               // 去它的右子树

    }

}

/*后序遍历求二叉树的高度递归算法*/
/*思路（递归定义）：如果bt为空，那么为0
如果非空，那么就是左右子树高度的最大值加一*/
int PostTreeDepth(BiTree bt)//BiTree
{
    int hl , hr , max;
    if(bt !=NULL){
        hl = PostTreeDepth(bt->lchild);
        hr = PostTreeDepth(bt->rchild);
        max = (hl > hr? hl : hr);
        return (max+1);
    }
    else
    {
        return 0; //之所以return 0 是要让空树的高度为0
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