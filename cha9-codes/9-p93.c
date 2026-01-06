#include <stdio.h>
unsigned long fact(unsigned long n);

int main() {
  int n;
  
  printf("输入要求阶乘的整数n=");
  scanf("%d",&n);
  printf("%d的阶乘=%d",n,fact(n));
  
  return 0;
}

unsigned long fact(unsigned long n)
{
	if (n <= 1) return 1;
	//else return fact(n - 1) * n;
  return fact(n - 1) * n;
}
