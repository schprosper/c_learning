#include <stdio.h>//可以用sizeof来看数组字节
int main (){
    int a[5] = {[0] = 1, [3] =4,5};
    printf("%lu\n",sizeof(a));
    int i ;
    // const int a = 5;
    for (i = 0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("%d\t",a[i] );
    }
}