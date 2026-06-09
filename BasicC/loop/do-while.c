#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//循环继续下去的条件，和终止的条件。
int main (){
    srand (time(0));
    int number = rand()%100+1;
    int count = 0;
    int a = 0;
    printf ("我想好了");
    do {
        printf ("猜吧：");
        scanf ("%d",&a);
        ++ count ;
        if( a > number ){ printf("你猜的数字大了");}
        else if(a < number ) {printf("小了");}
        //因为级联，所以也得有条件
    } while (a != number);

    printf ("你猜了%d次",count);
}
