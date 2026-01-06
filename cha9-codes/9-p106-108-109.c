#include <stdio.h>
int sum_digits(int n);

int main() {
  int n=256;

  printf("%d所有位数字之和=%d",n,sum_digits(n));

  return 0;
}

int sum_digits(int n)
{
  int sum = 0;   //local variable
  while (n > 0) {
	sum += n % 10;
	n /= 10;
  }
	  
  return sum;
}

void f(void)
{
  int i; //作用范围从该处到本函数结束
  //static int i;   //static local variable 
}