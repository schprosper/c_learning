#include <stdio.h>
int f(int a[10]) ;
int g(int a[10][20]);

int main() {
    
    return 0;
}

int f(int a[10]) //一维数组参数
//int f(int a[])  //no length specified

{
	int b[10]={1,2},i,j,c[10][20]={{1,2,3,4,5,6,7,8,9,10}};
	
	i=f(b);
    j=g(c);

	return 0;
}

int g(int a[10][20]) // 二维数组参数 
{
	return 0;
}
