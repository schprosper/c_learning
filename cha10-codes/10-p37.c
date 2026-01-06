#include <stdio.h>

int main() {
  char s1[100], s2[100];
  //s1 = "abc"; 	// 错误:数组名用作=的左操作数是非法的
  //s2 = s1; 	//错误用法
  char s3[100] = "abc"; //正确：在声明数组时，用=初始化字符数组
  
  if (s1 == s2) //错误用法 
  return 0;
}