#include <stdio.h>

double average(double a, double b)
{
  return (a + b) / 2;
}

int main() {
  double x=1.2, y=3.6, avg;
  
  avg = average(x, y);//函数返回值保存在变量中

 if (average(x, y) > 0)
	printf("Average is positive\n");

  printf("The average is %g\n", average(x, y));

  average(x, y);//函数返回值没有保存到变量，被丢弃了

  return 0;
}