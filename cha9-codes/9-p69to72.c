#include <stdio.h>
//void store_zeros(int a[], int n);
//void store_zeros(const int a[], int n);//采用const关键字,保护数组元素在函数内不被修改
void store_zeros(int *a, int n);//将形参a声明为指针，等同于将其声明为数组，编译器将这两种声明方式视为等价!!!

int main() {
  int b[4]={1,2,3,4}, n=4,i;
  
  store_zeros(b, n);
  
  for(i=0;i<4;i++)
    printf("b[%d]=%d\n",i,b[i]);

/*
  int b[100]={1,2};

  store_zeros(b, 100);
    
  printf("b[0]=%d,b[1]=%d",b[0],b[1]);
  */
  return 0;
}

/*
void store_zeros(int a[], int n)
{   
  int i;

  for (i = 0; i < n; i++) 
	  a[i] = 0;
}
*/
/*
void store_zeros(const int a[], int n)
{   int i;
	for (i = 0; i < n; i++)
	  a[i] = 0;  //错误：expression must be a modifiable lvalue
}
*/

void store_zeros(int *a, int n)
{   int i;
	for (i = 0; i < n; i++)
	a[i] = 0;
}

