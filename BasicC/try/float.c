#include <stdio.h>
void main(){
     printf("输入");
     double foot ;
     double inch ;
     scanf("%lf %lf",&foot , &inch) ;
     printf("height is %f \n",((foot + inch / 12.0)* 0.3084));//printf(“要输入的文字+ %f +换行吗”  ， 第一个占位符  ， 第二个占位符  )
}