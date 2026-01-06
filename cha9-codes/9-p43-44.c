#include <stdio.h>
#define LEN 10

int sum_two_dimensional_array(int [][LEN], int n);
//int sum_two_dimensional_array(int a[][], int n, int m);//错误：a是个二维数组，没有指定a中列的数量

int main(void)
{
    int b[3][LEN], total, i, j;
    
    for (i = 0; i < 3; i++)
        for (j = 0; j < LEN; j++)
            b[i][j]=1;
    
    total = sum_two_dimensional_array(b, 3);
    //total = sum_two_dimensional_array(b, 3, 10);

    printf("sum= %d\n",total);}


int sum_two_dimensional_array(int a[][LEN], int n)
{
    int i, j, sum = 0;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < LEN; j++)
	
    sum += a[i][j];
    
    return sum;
}

/*
int sum_two_dimensional_array(int a[][], int n, int m)
{
    int i, j, sum = 0;
    
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
	       sum += a[i][j];
    
    return sum;
}
*/