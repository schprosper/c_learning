#include <stdio.h>
int main (){
    int sum = 0;
    int n = 0;
    int a;
    int average;


    scanf ("%d",&a);
    
    while (a != -1){
        sum += a;
        n ++;
        scanf ("%d",&a);
    }

    printf ("%f",1.0*sum/n);

}