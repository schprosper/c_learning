#include <stdio.h>
//int square(int n);//更好的解决方案是在调用square函数前提供其原型

int main(void)
{
	double x = 3.0;
	
	//printf("Square: %d\n", square(x));//依赖默认的实际参数提升是危险的
    //printf("Square: %d\n", square((int) x));//强制转换为正确的类型
	
	return 0;
}

int square(int n)
{
	return n * n;
}