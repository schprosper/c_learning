
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;

//简单选择排序
void  SelectSort(RecordType r[], int length);


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
	
	SelectSort(r,len);
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
	
}
//简单选择排序
void  SelectSort(RecordType r[], int length)
/*对记录数组r做简单选择排序，length为数组的长度*/
{
	int i,j,k;
	int n;
	RecordType x;
    n=length;
	for ( i=1 ; i<= n-1; ++i)  
	{
		k=i;
		for ( j=i+1 ; j<= n ; ++j) 
			if (r[j].key < r[k].key ) 
				k=j;
			if ( k!=i) 
			{ 
				x= r[i]; 
				r[i]= r[k];
				r[k]=x;
			}
	}
	
} /* SelectSort  */ 