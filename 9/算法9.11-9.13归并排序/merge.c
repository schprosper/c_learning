
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct
{
	KeyType key;
	OtherType other_data;
}RecordType;

//合并为有序序列
void Merge(RecordType r1[],  int low,   int mid,   int high,  RecordType  r2[]);
//归并排序
void   MSort(RecordType  r1[],  int  low,  int  high,  RecordType  r3[]);
//调用归并排序
void   MergeSort ( RecordType  r[],  int  n );


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
	MergeSort(r,len);
	for(i=1;i<=len;i++)
		printf("%d  ",r[i].key);
	printf("\n");
	
}


//合并为有序序列
void Merge(RecordType r1[],  int low,   int mid,   int high,  RecordType  r2[])
/* 已知r1[low..mid]和r1[mid+1..high]分别按关键字有序排列，将它们合并成一个有序序列，存放在r2[low..high] */
{ 
	int i,j,k;
	i=low;
	j=mid+1;
	k=low;
	while ( (i<=mid)&&(j<=high)  )
	{
		if ( r1[i].key<=r1[j].key )
		{
			r2[k]=r1[i];
			++i;
		}
		else 
		{
			r2[k]=r1[j];
			++j;
		}
		++k;
	}
	while( i<=mid )
	{
		r2[k]=r1[i];
		k++;
		i++;
	}
	while( j<=high)
	{
		r2[k]=r1[j];
		k++;
		j++;
	}
} /* Merge */ 

//归并排序
void   MSort(RecordType  r1[],  int  low,  int  high,  RecordType  r3[])
/* r1[low..high]经过排序后放在r3[low..high]中，r2[low..high]为辅助空间 */ 
{
	int mid;
	RecordType  r2[20];
	if ( low==high ) 
		r3[low]=r1[low];
	else
	{
		mid=(low+high)/2;
        MSort(r1,low, mid, r2);
        MSort(r1,mid+1,high, r2);
        Merge (r2,low,mid,high, r3);
}
} /*   MSort  */ 
//调用归并排序
void   MergeSort ( RecordType  r[],  int  n )
/* 对记录数组r[1..n]做归并排序 */ 
{
	MSort ( r,  1,  n,  r );
}
