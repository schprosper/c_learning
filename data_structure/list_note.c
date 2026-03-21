//全局区域
#define MaxSize 50
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int data[MaxSize];
    int last;//last是最后一个元素的下标。。。。
} SeqList;

typedef int ElemType;
/*如果我动态分配内存*/
/*动态分配内存，不是用多少内存给多少，自动扩容，而是让结构体占得内存少点*/
typedef struct {
    ElemType *data;
    int last;
}SeqList2;

//函数区

/* 规定大小初始化*/
/*静态的，数组空间已经包含在结构体里面，
这里返回结构体，也可以返回指针，但是没必要*/
void InitList(SeqList *L)
{
    L->last = -1;
}
SeqList InitList_nod(){
    SeqList L;
    L.last = -1;
    return L;

}

/*分配内存初始化——不是容量可自动增长的扩容顺序表！！！！*/
/*不加参数也可以*/
/*返回指针，因为申请内存的时候，只能给你指针
所以返回类型写成 SeqList2* ，主函数里也用指针接收
因此，在主函数使用的时候，也得是L->访问*/
SeqList2* initList()

{
    //L本身作为指针变量传进来
    //这个内存我要存放 seq结构体 的数据类型——给予空间+名字？
    SeqList2 *L = (SeqList2*)malloc(sizeof(SeqList2));//放东西地方的指针
    //但是data没地方放,所以data另放
    L->data = (ElemType*)malloc(sizeof(ElemType) * MaxSize);

    L->last =-1;
    return L;

}

/*遍历+输出结果*/
void ListElem(SeqList *L)
{
    for(int index = 0;index<=L->last;index++)
    {printf("%d ",L->data[index]);}
    printf("\n");
}

void ListElem2(SeqList2 *L)
{
    for(int index = 0;index<=L->last;index++)
    {printf("%d ",L->data[index]);}
    printf("\n");
}


/*查找运算,在第几个位置*/
int findElem(SeqList *L,int e){
    for (int idx = 0;idx<= L->last;idx++){
        if(L->data[idx]==e){return idx+1;}
    }
    return 0;
}

int findElem2(SeqList2 *L,int e){
    for (int idx = 0;idx<= L->last;idx++){
        if(L->data[idx]==e){return idx+1;}
    }
    return 0;
}

/*尾部插入 Listappend(SeqList *L,int e)*/
bool Listappend(SeqList *L,int e){
    if(L->last >= MaxSize -1){return false;}
    else { L->data[L->last + 1 ] = e;}
    L->last ++;
    return true;
}

bool Listappend2(SeqList2 *L,int e){
    if(L->last >= MaxSize -1){return false;}
    else { L->data[L->last + 1 ] = e;}
    L->last ++;
    return true;
}

/*有限长度的顺序表的插入
需要参数(SeqList *L,int i ,int e)*/
bool ListInsert(SeqList *L,int i ,int e){
    if(i<1 || i-1 > L->last+1){return false;}
    if(L->last >= MaxSize-1){return false;}
    for(int j = L->last;j>i-1;j--)
        L->data[j+1] = L->data[j];//首个元素为0，下标正好
    L->data[i -1] = e;
    L->last++;
    return true;
}

bool ListInsert2(SeqList2 *L,int i ,int e){
    if(i<1 || i-1 > L->last+1){return false;}
    if(L->last >= MaxSize-1){return false;}
    for(int j = L->last;j>i-1;j--)
        L->data[j+1] = L->data[j];//首个元素为0，下标正好
    L->data[i -1] = e;
    L->last++;
    return true;
}
/*删除操作,并将被删除的元素用引用变量来返回*/
bool ListDelete(SeqList *L,int i,int *e)

{
    int i_pos = i-1;
    if(i_pos<0||i_pos>L->last){return false;}
    *e = L->data[i_pos];
    
    for(int j = i_pos;j<L->last;j++)
    {L->data[j] = L->data[j+1];}

    L->last--;

    return true;
}

/*合并算法--从小达到的排列*/
void merge(SeqList *LA,SeqList *LB,SeqList *LC){
    
    int a =0, b=0, c=0;
    //c 是下一个要插入位置的下标。
    while (a<=LA->last&&b<=LB->last)
    {
        if(LA->data[a] <=LB->data[b])
        {
            LC->data[c] = LA->data[a];
            a++;
            c++;
        }
        else
        {
            LC->data[c] = LB->data[b]; 
            b++;
            c++;
        }
    }

    //复制完成，开始剩余元素链接
    while (a<=LA->last)
    {
        LC->data[c] = LA->data[a];
        c++;
        a++;
    }
    while (a<=LB->last)
    {
        LC->data[c] = LB->data[b];
        c++;
        b++;
    }

    LC->last = c -1;
    // or
    LC->last = LA->last+LB->last +1;
}

//主循环区
int main(void)
{

/*
    SeqList list;//栈内存
    InitList(&list);//要传内存地址才能被指针收到
    printf("内存占用%zu\n",sizeof(list.data));
    
    Listappend(&list, 88);
    Listappend(&list, 67);
    Listappend(&list, 40);
    Listappend(&list, 8);
    Listappend(&list, 23);
    ListElem(&list);
    ListInsert(&list, 2, 18);
    ListElem(&list);
    int pos=0;
    pos = findElem(&list,40);
    printf("%d\n",pos);
*/    
    
/*=================================动态内存===========================================*/
/*不同点---1. 初始化得到指针---由此推导出参数传入方式*/    

    SeqList2 *list2 = initList();
    printf("内存占用%zu\n",sizeof(list2->data));//占用8，很少很少的！！
    Listappend2(list2, 88);
    Listappend2(list2, 67);
    Listappend2(list2, 40);
    Listappend2(list2, 8);
    Listappend2(list2, 23);
    ListElem2(list2);
    ListInsert2(list2, 2, 18);
    ListElem2(list2);
    int pos2 = 0;
    pos2 = findElem2(list2, 40);
    printf("%d\n", pos2);

    
    return 0;


}



