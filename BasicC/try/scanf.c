#include <stdio.h>
void main(){
    int chi;
    int cun;
    printf("chi cun:");//如果你说hello，还会出现数字
    scanf("%d %d", &chi ,&cun);//加什么读什么，无论有没有空格,或者给个回车
    //出现在scanf里面的东西，是他必须你输入的东西
    printf("%d + %d = %d\n",chi ,cun  , chi + cun );
}
