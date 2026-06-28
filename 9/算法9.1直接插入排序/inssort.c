
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;

//直接插入排序
void   InsSort(RecordType  r[],  int length);


void main()
{
	int i,j;
	RecordType r[20];
	int len;
	printf("请输入待排序记录的长度:");
	scanf("%d",&len);
	for(i=1;i<=len;i++)
	{
		printf("请输入第%d个记录元素:",i);
		fflush(stdin);
		scanf("%d",&j);
		r[i].key = j;
	}
	//没排序时候的序列
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");

	InsSort(r,len);
	//输出
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");

}

//直接插入排序
void   InsSort(RecordType  r[],  int length)
/* 对记录数组r做直接插入排序，length为数组中待排序记录的数目*/
{ 
	int i,j;
	for (i=2;  i<=length;  i++) 
	{
		r[0]=r[i];      /*将待插入记录存放到监视哨r[0]中*/
		j=i-1;	         
		while (r[0].key< r[j].key )     /* 寻找插入位置 */
		{
			r[j+1]= r[j]; 
			j=j-1;
		}
		r[j+1]=r[0];		         /*将待插入记录插入到已排序的序列中*/
	}
} /*  InsSort  */ 

/*递增，所以让大的往后移*/
void insSort(RecordType r[], int lenth)
{
	int i,j;
	for(i =2;i<=lenth;i++)
	{
		r[0]=r[i];//哨兵是用来移动的。
		j = i -1; //和谁比较，这里好像默认是递增有序
		while (r[0].key<r[j].key)
		{
			r[j+1] = r[j];
			j = j-1;
		}
		r[j+1] = r[0]; //向前加一位
		
	}
}



