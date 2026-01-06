/* volume1.c */
/* 提示用户输入正方形边长，计算并输出体积*/
#include <stdio.h>
int main(void) {
  int length, volume;//变量声明.
  
  printf("Enter the length of one side of the cube: ");//提示输入正方形边长
  
  scanf("%d",&length); //读入用户输入.
  volume = length * length * length; //计算
 
  printf("The length of one side of the cube: %d\n", length); //输出
  printf("The volume of the cube: %d\n", volume);  //输出
  
  return 0;
}
