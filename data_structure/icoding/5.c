#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;


#define MAX_CHILDREN_NUM 5
//普通树节点的定义--- common 
struct _CSNode
{
    DataType data;
    struct _CSNode* children[MAX_CHILDREN_NUM];//这个节点有多少个孩子
};
typedef struct _CSNode CSNode;


struct __Queue
{
    int i, j; //指向数组内元素的游标
    void** array;//指向指针的指针
};
typedef struct __Queue Queue;

Queue* create_queue(); //创建队列
bool is_empty_queue(Queue *tree); //队为空返回true,不为空时返回false
void* del_queue(Queue *tree); //结点指针出队
void add_queue(Queue *tree, void *node); //结点指针入队
void free_queue(Queue *tree); //释放队列


BiTNode* transform(CSNode *root);

/*如果要看，建议看第二个，第二个是默写的，有错题属性*/


/*
root：普通树根节点
BRoot：新建的二叉树根节点
Q：队列，里面两个指针为一组
TNode：当前正在处理的普通树节点
BNode：TNode 对应的二叉树节点
NewNode：TNode 的某个孩子新建出来的二叉树节点
pre：上一个孩子对应的二叉树节点*/

/*队列对应 PPT 里的层次遍历：从根开始，先进队，
然后每次出队一个结点，处理它的孩子，再把孩子入队。*/
BiTNode* transform(CSNode *root) {
    BiTNode *BRoot;
    Queue *Q;

    if (root == NULL) {
        return NULL;
    }

    // 创建二叉树根节点
    BRoot = (BiTNode*)malloc(sizeof(BiTNode));

    BRoot->data = root->data;
    BRoot->left = NULL;
    BRoot->right = NULL;
    //做完这一步之后，是双根节点构建好了的层序遍历。

    // 队列中成对存放：普通树节点、对应的二叉树节点
    Q = create_queue();

    add_queue(Q, root);
    add_queue(Q, BRoot);

    while (!is_empty_queue(Q)) {
        CSNode *TNode = NULL;
        BiTNode *BNode=NULL;
        BiTNode *pre=NULL; //pre：普通树的上一个孩子，对应的二叉树节点
        //pre 保存的是：刚刚创建出来的那个二叉树节点的地址。
        //——为了孩子兄弟表示法，对兄弟的操作
        int i;

        // 先出普通树节点，再出对应二叉树节点
        TNode = (CSNode*)del_queue(Q);
        BNode = (BiTNode*)del_queue(Q);



        //这里的层序遍历，不用cont来记，直接for循环来判断是否走完即可！！
        for (i = 0; i < MAX_CHILDREN_NUM && TNode->children[i] != NULL; i++)
         {
            BiTNode *NewNode;//NewNode：TNode 的某个孩子新建出来的二叉树节点

            NewNode = (BiTNode*)malloc(sizeof(BiTNode));

            NewNode->data = TNode->children[i]->data;
            NewNode->left = NULL;
            NewNode->right = NULL;


            /*下面，才是核心中的核心*/
            // 第一个孩子：接到父节点的 left
            if (i == 0) {
                BNode->left = NewNode;
            }
            // 后面的孩子：接到前一个孩子的 right
            else {
                pre->right = NewNode;
            }

            pre = NewNode;

            // 当前普通树孩子 和 对应二叉树节点 成对入队
            add_queue(Q, TNode->children[i]);
            add_queue(Q, NewNode); //看上去是NewNode，实际上是塞了个地址
            //如果为了好看的话，我觉得直接写 Bi+字母 即可
        }
    }

    free_queue(Q);
    return BRoot;
}




BiTNode* transform(CSNode *root) 
{
    // CSNode* TNode;
    // BiTNode* BiNode;
    // BiTNode* pre =NULL;
    /*这里主要考虑的是———下标和变量作用范围*/
    /*变量的定级== 看这个变量的任务范围是哪里*/
    /*
    1. 这个变量服务的是整个函数，还是某一轮 while，还是某一轮 for？
    2. 它的值要不要保留到下一轮 for？
    3. 进入下一轮外层循环时，它是不是应该重新开始？
    */

    BiTree Biroot = (BiTNode*)malloc(sizeof(BiTNode));
    Queue* Q; // Q和Biroot是在整个函数范围内有用处
    
    Biroot->data = root->data;
    Biroot->left = NULL;
    Biroot->right = NULL;
    


    Q = create_queue();

    add_queue(Q,root);
    add_queue(Q,Biroot);

    int i;
    while (!is_empty_queue(Q))// 每次while，是处理一个父节点的
    {
        CSNode* TNode;
        BiTNode* BiNode;
        BiTNode* pre =NULL;//应该放到这里
        
        
        TNode = del_queue(Q);
        BiNode = del_queue(Q);
        for(i=0; i<MAX_CHILDREN_NUM && TNode->children[i] !=NULL;i++)
        {
            BiTNode* NewBiNode = (BiTNode*)malloc(sizeof(BiTNode));

            NewBiNode->data = TNode->children[i]->data;
            NewBiNode->left =NULL;
            NewBiNode->right =NULL;

            if(i==0)
            {
                BiNode->left = NewBiNode;
            }
            else
            {
                pre->right = NewBiNode;
            }

            pre = NewBiNode;

            add_queue(Q,TNode->children[i]);
            add_queue(Q,NewBiNode);
        }
    }
    
    free_queue(Q);
    return Biroot;
}


//=============================第二题=======================================
/*
## 题目：

假设二叉树采用二叉链表方式存储， root指向根结点，p所指结点和q所指结点为二叉树中的两个结点，
编写一个计算它们的最近的共同祖先，函数定义如下：
BiTNode * nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q);
其中 root 指向二叉树的根结点，p 和 q 分别指向二叉树中的两个结点。  

在完成本题时，可利用 path 函数获取p和q两个结点到根结点之间的路径
path函数及栈相关定义如下：
*/
#define Stack_Size 50
typedef BiTNode* ElemType;
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool path(BiTNode* root, BiTNode* node, Stack* s);



void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false

/*
一个结点的所有祖先，其实就在 root 到这个结点的路径上。
栈，先进后出。有共同祖先，说明祖先和祖先之前的路径完全一样，
也就是栈内容一模一样。
*/

/*
二叉树路径类 / 最近公共祖先 LCA\
先分别求 root -> p 和 root -> q 的路径，
然后从两个结点往根方向回退，第一次遇到相同结点，就是最近共同祖先。
*/
BiTNode * nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q) {
    Stack Sp, Sq;
    BiTNode *xp = NULL;
    BiTNode *xq = NULL;
    BiTNode *temp = NULL;

    init_stack(&Sp);
    init_stack(&Sq);

    // 防御性判断：根为空、p/q为空，直接返回 NULL
    if (root == NULL || p == NULL || q == NULL) {
        return NULL;
    }

/*
如果不允许直接访问 Sp.top，只允许使用 push/pop/top/is_empty，这题怎么写？
*/

    // 分别求 root 到 p、root 到 q 的路径
    if (!path(root, p, &Sp) || !path(root, q, &Sq)) {
        return NULL;
    }

    // 先让两个栈的栈顶处在同一深度
    while (Sp.top > Sq.top) {
        pop(&Sp, &temp);
    }
    while (Sq.top > Sp.top) {
        pop(&Sq, &temp);
    }

    // 同时向根方向回退，第一次相同就是最近共同祖先
    while (!is_empty(&Sp) && !is_empty(&Sq)) {
        pop(&Sp, &xp);
        pop(&Sq, &xq);

        if (xp == xq) {
            return xp;
        }
    }

    return NULL;
}

/*
首先是函数理解有问题：
最重要的是看返回值。你要有的，是一个实体栈啊！
之后是前缀名。
init：把已经存在的东西整理好。
create：从无到有创造一个东西。
*/
//BiTNode* ElemType -- 栈里面要存这个东西

BiTNode * nearest_ancestor(BiTree root, BiTNode *p, BiTNode *q)
{
    Stack Sp;
    Stack Sq;
    
    init_stack(&Sp);
    init_stack(&Sq);

    BiTNode* px= NULL;
    BiTNode* qx= NULL;

    if(root ==NULL|| &Sp==NULL||&Sq == NULL)
    {
        return NULL;
    }

    if(!path(root,p,&Sp)||!path(root,q,&Sq))
    {
        return NULL;
    }

    while(Sq.top < Sp.top)
    {
        pop(&Sp,&px);
        //qx是Bi*类的变量，pop直接修改Bi*的值，所以，需要（Bi*）* 二重指针。

    }
    while(Sq.top > Sp.top)
    {
        pop(&Sq,&qx);
    }

    while(!is_empty(&Sp) && !is_empty(&Sq))
    {
        pop(&Sp,&px);
        pop(&Sq,&qx);

        if(px == qx)
        {
            return qx;
        }
    }

    return NULL;



}












// ======================第三题---非递归遍历===========================
/*
二叉树非递归遍历 / 栈保存路径 / 非递归后序遍历变形
*/
/*
假设二叉树采用二叉链表方式存储， root指向根结点，node 指向二叉树中的一个结点，编写函数 path，计算root到 node 之间的路径，（该路径包括root结点和 node 结点）。path 函数声明如下：

bool path(BiTNode* root, BiTNode* node, Stack* s);
其中，root指向二叉树的根结点，node指向二叉树中的另一结点，s 为已经初始化好的栈，该栈用来保存函数所计算的路径，如正确找出路径，则函数返回 true，此时root在栈底，node在栈顶；如未找到，则函数返回 false, 二叉树的相关定义如下：

typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;
栈的相关定义及操作如下：

#define Stack_Size 50
typedef BiTNode* ElemType;
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false
在提示中，树用缩进的形式展示，如二叉树
*/

#include <stdlib.h>
#include <stdio.h>


/*
递归的形式----犯了个重要错误，就是根节点必须要判断。
递归，其实是吧二叉树视为无数个子树，
因此二叉树，无论如何都要判断根节点为空。

指针定义的时候，如果不直接赋值那么顺手写NULL
*/
/*  BiTNode*  ElemType
bool push(Stack* S, ElemType x); 这里返回的是boll
 */
bool pathfff(BiTNode* root, BiTNode* node, Stack* s)
// 这里有个很重要的理解思维—— 根节点是相对的！表示“当前递归层的根”
{
    if (root == NULL) {
    return false;
    }

    //要找node节点 已经有了一个栈了。
    if(!push(s,root))
    {
        return false;
    }

    if(root == node)
    {
        return true;
    }

    if(pathfff(root->left ,node, s) == true)
    {
        return true;
    };
    if(pathfff(root->right ,node, s) == true)
    {
        return true;
    }

    //都失败了，说明不在这个节点的左右子树上
    BiTNode* NoHere = NULL;
    pop(s,&NoHere);

    return false;


}


//===========================第三题/*非递归寻找的方法*/==============================
/*非递归寻找的方法*/
/*
root 当前正在访问的结点

这题的精髓不是某一版代码，而是这个不变量：
栈 s 始终保存 root 到当前搜索位置的路径。
很抽象的一个概念——就是S里面到底放了什么东西是不变的
*/
bool path(BiTNode* root, BiTNode* node, Stack* s)
{
    BiTNode *last = NULL;
    if (root == NULL || node == NULL || s == NULL) {
        return false;
    }

    //寻找路径栈循环
    while (root != NULL || !is_empty(s)) {

        // 1. 一路向左，走到哪里就把哪里压入路径栈
        //左走循环
        while (root != NULL) {
            !push(s, root);
            if (root == node) {
                return true;
            }
            root = root->left;
        }

        // 2. 左边走不下去了，看栈顶结点
        top(s, &root);

        // 3. 如果栈顶结点有右子树，并且右子树没走过，就转去右子树
        if (root->right != NULL && root->right != last) {
            root = root->right;
        }
        // 4. 否则说明左右都处理完了，弹栈回退
        else {
            pop(s, &root);
            last = root;
            root = NULL;
            //这里设置为NULL，是防止吧pop出来的节点当成要访问的节点来看。
        }
    }

    return false;
}

/*
从一个节点来分析，比如满深度为3的二叉树的B位置。
-----分为，深左、深右和回退三个动作
这根据节点状态，这三个动作有检测顺序（状态机）也就是下面的描述：

一路往左走，走到哪儿就把结点压栈；
左边走不下去时，看栈顶结点有没有没走过的右子树；如果有就去右子树，
如果没有就弹栈回退。找到目标时，栈里正好就是 root 到 node 的路径。

这个顺序就是代码所示的ifelse顺序————并非彻底并列，而是{}搞顺序。
而检测左右子树是否走过，不仅顺序问题，还有检测问题，这就是is_read的作用。
这个才是需要理解的。

while循环做的的是操作栈循环。
*/


bool path(BiTNode* root, BiTNode* node, Stack* s)
{  
    if(root ==NULL || node == NULL || s ==NULL)
    {
        return false;
    }

    push(s,root);

    BiTNode* last = NULL;
    while(!is_empty(s))
    {
        while(root != NULL)
        {
            root = root->left;
            push(s,root);
            if(root == node)
            {
                return true;
            }
        }

        top(s,&root);

        if(root->right !=NULL ||root->right != last)
        {
            root = root->right;
            push(s,root);
            if(root == node)
            {
                return true;
            }
        }
        else
        {
            pop(s,&root);
            last = root;
            root = NULL;
        }
    }

    return false;
}

//==============第四题——前序遍历——利用栈的基本操作写出非递归形式==============

/*
当前结点不空：
    访问当前结点
    当前结点入栈，保存起来，之后回来找右子树
    去左孩子

当前结点为空：
    走到底了（或者左边或者右边，无所谓，栈尾存的是他的父亲
    弹出上一个保存的结点
    去它的右孩子
*/
void pre_order(BiTree root) {
    Stack S;
    init_stack(&S);
    while (root != NULL || !is_empty(&S)) {
        if (root != NULL) {
            visit_node(root);// 遍历只是顺序问题，对节点怎么操作visit，随便
            push(&S, root);
            root = root->left;
        }
        else {
            pop(&S, &root);
            root = root->right;
        }
    }
}

