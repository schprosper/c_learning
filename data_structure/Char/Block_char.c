#include <stdio.h>
#include <stdlib.h>

#define  BLOCK_SIZE  4  /*每结点存放字符个数*/

/*
4. next 指向下一个块。
5. head 指向第一个块。
6. tail 指向最后一个块，方便连接两个串。
*/


/*这个是一个节点的情况*/
typedef struct Block{
    char ch[BLOCK_SIZE];	 /*BLOCK_SIZE为1，就是单链表结构*/
    struct Block   *next;
} Block;

/*表示整个块链串*/
typedef struct {
    Block   *head;
    Block   *tail; 	/* tail联接2个串使用*/
    int     length;/*整个串的字符个数*/
} BLString;

