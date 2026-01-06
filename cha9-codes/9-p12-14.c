#include <stdio.h>

double average(double a, double b)
{
	  double sum;       //declaration 
	  sum = a + b;      //statement
	  return sum / 2;   //statement 
}

void print_pun(void)
{
}

int main() {
    int x=1.1,y=2.0;
    
    average(x, y);
    
    print_pun();
    //print_pun;//错误：丢失圆括号，不会直接报错，但是结果未定义
    
    return 0;
}