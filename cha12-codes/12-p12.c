#include <stdio.h>
#include <stdlib.h>

//******************类型定义****************/
#define MAX_ID 100
#define MAX_NAME 100
#define MAX_GOODS 1000000

//定义商品结构
typedef struct {   
    char id[MAX_ID];   //商品ID号 
    char name[MAX_NAME];  //名称 
    int price;    //价格
    double discount; //折扣
    int amount; //数量
    int remain; //剩余数量
}Goods;

//定义结点结构
struct Node{    
    Goods goods; 
    struct node *next;
};

int main() 
{
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	free(n);

  return 0;
}
