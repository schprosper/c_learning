#include <stdio.h>

void  main(){
    int n=0;
    int a=1;
    int i = 0 ;
    scanf ("%d",&n);
    while (n !=0 ){

        a *= n;
        --n; }

    printf ("%d",a);
}