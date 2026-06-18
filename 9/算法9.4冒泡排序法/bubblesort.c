
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;

//冒泡排序
void  BubbleSort(RecordType r[], int length );

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
	
	BubbleSort(r,len);
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
	
}

//冒泡排序
void  BubbleSort(RecordType r[], int length )
/*对记录数组r做冒泡排序，length为数组的长度*/
{
	int n,i,j;
	int change;
	RecordType x;
	n=length;  
	change=TRUE;
		for ( i=1 ; i<= n-1 && change ;++i ) 
		{
			change=FALSE;
				for ( j=1 ; j<= n-i ; ++j) 
					if (r[j].key > r[j+1].key )  
					{
						x= r[j];
						r[j]= r[j+1];
						r[j+1]= x;
						change=TRUE;
					} 
		}
} /*  BubbleSort  */ 

