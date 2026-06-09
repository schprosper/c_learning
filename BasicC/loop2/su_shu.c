//用for？
#include <stdio.h>
int main()
{
    int x = 9;
    //scanf("%d", &x);

    int i=1;
    int isPrime = 1;
    for (i =2; i< x; i++){
        if(x%i == 0){isPrime = 0; continue; }
        printf ("%d\n",i);
    }
    if (isPrime == 0){printf("no");}
    else {printf("yes");}
    return 0;
}