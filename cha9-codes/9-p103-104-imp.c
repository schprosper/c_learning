// Sorts an array of integers using Quicksort algorithm 
#include <stdio.h>
#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
  int a[N], i;
  
  printf("Enter %d numbers to be sorted: ", N);
  
  for (i = 0; i < N; i++)
    scanf("%d", &a[i]);

  quicksort(a, 0, N - 1);

  printf("In sorted order: ");
  for (i = 0; i < N; i++)
    printf("%d ", a[i]);
  printf("\n");
 
return 0;
}

void quicksort(int a[], int low, int high)
{
  int middle;

  if (low >= high) return;
    middle = split(a, low, high);

  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
	int part_element = a[low];
  	
    for (;;) {
      while (low < high && part_element <= a[high])
      	high--;  // 找到一个比part_element小的a[high] 为止 
      
      if (low >= high) break;
    	a[low++] = a[high]; // 把小a[high]值拷贝到a[low]位置，low指针+1 
      
      while (low < high && a[low] <= part_element)
      	low++; //a[high] // 找到一个比part_element大的a[low] 为止 
  	  
      if (low >= high) break; 
   		a[high--] = a[low]; // 把大a[low]值拷贝到a[high] 位置，high指针-1
  	}
	
  a[high] = part_element;
  	
  return high;
}
