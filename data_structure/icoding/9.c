#include <stdio.h>

/*
直接插入排序：拿一个数，插到前面有序区。（假设左大右小）
必须是数组。
*/
void InsertSort(int a[], int n) {
    int i, j, temp;
/*
i：当前要插入的元素位置
temp：把 a[i] 先存起来，防止被覆盖
j：从 i-1 开始，往前找插入位置，j是和有序数组中的谁比较
*/

    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = temp;
    }
}
void InsertSort(int a[], int n)
{   
    int i , j ,temp;
    for(i = 1; i<n ; i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j] > temp)
        {
            a[j+1] = a[j];  // 最核心，如何往右边放
            j--;
        }
        a[j+1] = temp;

    }
    
}



/*
冒泡排序：从头冒泡，相邻交换，把最大值推到后面。
*/
void BubbleSort(int a[], int n) {
    int i, j, temp;
    int flag = 1;
/*
i：第几趟冒泡。 n个数据最多 n-1次冒泡
j：本趟正在比较 a[j] 和 a[j+1]
temp：交换用的临时变量
flag：这一趟有没有发生交换 那么就是0；
*/

    for (i = 0; i < n - 1 && flag == 1; i++) {
        flag = 0;

        for (j = 0; j < n - 1 - i; j++)//这里还能利用一次i
         {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
    }
}

//手写的，错误放到上面去了
void BubbleSort(int a[], int n)
{
    int i , j , temp;
    int flag = 1;

    for(i=0;i<n-1 && flag == 1; i++)
    {
        flag = 0;
        for(j = 0; j<n-1-i ;j++) 
        {
            if(a[j+1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j+1] = temp;
                flag = 1;
            }
        }
    }
}

