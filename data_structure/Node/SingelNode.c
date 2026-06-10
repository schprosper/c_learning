#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
    
}Node , *LinkList;

Node* insertTail(Node *L, ElemType e) {
    Node *curr = L;//当前节点
    Node *newNode = NULL;

    while (curr->next != NULL)
    //直接同时处理了空表！！！
    {
        curr = curr->next;
    }

    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        //给予内存错误。
        return curr;
    }

    newNode->data = e;
    newNode->next = NULL;
    curr->next = newNode;

    return newNode;
}

Node* initList()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head ->data = 0;
    head ->next = NULL;
    return head;

}

Node* get_tail(Node *L){
    while(L->next != NULL){
        L = L->next;
    }

    return L;

}

void listNode(Node *head){
    Node *p = NULL;
    p = head->next;
    
    while (p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }

    printf("\n");


}

/*应用:用空间换时间，最多只有21个节点。
创造一个数组，开辟一个22个数组的空间。
然后做下标！！*/
//对照“数组”进行删除

//删除绝对值相同的节点
void removeNode(Node* L,int n){
    
    Node* p = L;
    int index = 0;
    
    int *q = (int*)malloc(sizeof(int) * (n+1));
    //用指针去操作数组
    for (int i = 0; i<=n ; i++)
    {
        *(q + i) = 0;
    }

    
    //开始往数组里面遍历
    while(p->next !=NULL)
    {
        index = abs(p->next->data);
        if(*(q+index) == 0)
        {
            *(q + index) = 1;
            p = p->next;//然后要往下走！
        }
        else
        {

            
            Node* temp =p->next;
            p->next = temp->next ; //不能 next之后再next
            //程序执行到这一步会改变数的值，必须有个东西，让他在原值上修改
            /*
            如果是  p->next = p->next->next; A（p） B C D
            free(p->next);那么这时候被free掉的就是C了
            */
            free(temp);
           
        }
        

    }
    free(q);
    
}

//反转链表
Node* reverseList(Node* head) {
    Node *first = NULL;
    Node *second = head->next;
    Node *third = NULL ;

    while (second !=NULL)
    {
        third = second->next;
        second->next = first;//这一步，消除了原本的，生成了新的
        first = second;
        second = third;
    }

    Node *hd = initList();
    hd->next = first;

    return hd;
}




int main()
{
    Node *list = initList();
    
    Node *tail = get_tail(list);

    tail = insertTail(tail, 21);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, -15);
    tail = insertTail(tail, 7);
    tail = insertTail(tail, 15);

    listNode(list);

    Node* reverse = reverseList(list);

    listNode(reverse);

    return 0;
}