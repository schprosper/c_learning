//最大公约数——辗转相除法
//变量画出表格验算试试
#include <stdio.h>

int main() {
    int a,b;
    int t;
    scanf ("%d %d",&a,&b);
    while (b !=0){
        t =a%b;
        a=b;
        b=t;
        printf("%d,%d,%d\n",a,b,t);
    }

    return 0; 
}

