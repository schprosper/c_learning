#include <stdio.h>
int main(){
    double a;
    double b;
    printf("请输入两个数:");

    scanf("%lf %lf",&a,&b);

    double max ;

    if (a>b)
    {
        max = a;
    }else {max = b;
    }

    printf("%lf\n",max);
    
    return 0;
}