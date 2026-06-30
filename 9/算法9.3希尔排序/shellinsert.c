
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;

//希尔插入
void  ShellInsert(RecordType r[], int length,  int  delta);
//希尔排序
void  ShellSort(RecordType r[], int length, int delt[], int n);


void main()
{
	int i,j;
	RecordType r[20];
	int len;
	int delta[3]={4,2,1}; //这里最终会回归为1
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
	
	ShellSort(r,len,delta,3);
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
	
}

//希尔插入
void  ShellInsert(RecordType r[], int length,  int  delta)
/*对记录数组r做一趟希尔插入排序，length为数组的长度,delta 为增量*/
{
	int i,j;
	/*第一层嵌套的是每个子序列的第一个*/
	/*这里是先给子序列的第二个，在子序列内进行排序（第一个自然有序）
	，而不是每个子序列都排完了再进行的排序*/
	for(i=1+delta;i<= length; i++)      
	/* 1+delta为第一个子序列的第二个元素的下标 */
		if(r[i].key < r[i-delta].key)
		{
			r[0]= r[i];           /*  备份r[i]  (不做监视哨) */
				for(j=i-delta; j>0 &&r[0].key < r[j].key; j-=delta)
					{
						r[j+delta]= r[j];
					}
				r[j+delta]= r[0];
		}
}/*ShellInsert*/
//希尔排序
void  ShellSort(RecordType r[], int length, int delt[], int n)
/*对记录数组r做希尔排序，length为数组r的长度，delta 为增量数组，n为delta[]的长度 */
{ 
	int i;
	for(i=0 ;  i<=n-1;  ++i)
		ShellInsert(r, length, delt[i]);
}
