
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;

//折半插入排序
void    BinSort (RecordType  r[],  int length);


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
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
	
	BinSort(r,len);
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
	
}

//折半插入排序
void    BinSort (RecordType  r[],  int length)
/*对记录数组r进行折半插入排序，length为数组的长度*/
{
	int i,j;
	RecordType x;
	int low,high,mid;
	for (  i=2; i<=length ; ++i ) 
	{
		x= r[i];
		low=1;  high=i-1;
		while (low<=high )                  /* 确定插入位置*/ 
		{
			mid=(low+high) / 2;
			if (  x.key< r[mid].key   )    
				high=mid-1;
			else 
				low=mid+1;
		}
		for (  j=i-1 ; j>= low; --j )   r[j+1]= r[j];         /*  记录依次向后移动 */ 
		r[low]=x;                                                            /* 插入记录 */ 
	}
}/*BinSort*/
