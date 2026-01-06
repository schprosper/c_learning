#include <stdio.h>
int sum_two_dimensional_array(int n, int m, int a[n][m]);
//int sum_two_dimensional_array(int n, int m, int a[*][*]);
//int sum_two_dimensional_array(int n, int m, int a[][m]);
//int sum_two_dimensional_array(int n, int m, int a[][*]);

int main() {
    int a[2][3]={{1,2,3},{4,5,6}};

    printf("{{1,2,3},{4,5,6}}元素值和=%d",sum_two_dimensional_array(2, 3, a));
    
    return 0;
}

int sum_two_dimensional_array(int n, int m, int a[n][m])
{
	int i, j, sum = 0;
	for (i = 0; i < n; i++)
	    for (j = 0; j < m; j++)
	      sum += a[i][j];
	return sum;
}
