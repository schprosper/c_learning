/* volume.c */
/*给出正方形的边长，计算其体积. */
#include <stdio.h>
int main(void) 
{
   int length, volume;  // 变量声明.
   length = 9; // 给正方体的边长赋值
   volume = length * length * length; // 计算体积
   
   printf("The length of one side of the cube: %d\n", length); // 输出正方体的边长
   printf("The volume of the cube: %d\n", volume);  // 输出正方体的体积
   
   return 0;
}


