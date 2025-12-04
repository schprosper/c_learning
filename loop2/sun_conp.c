#include <stdio.h>
int main ()
{
    int i = 0;
    int n;
    double sum = 0.0;
    double sign = 1;
    //scanf ("%d",n);
    n = 100;
    for (i=1;i<n;i++)
    {
        sum += sign/i;
        sign = - sign ;//除号一边是浮点数，另一边也是浮点数
    
    }
    printf("f(%d)=%f\n",n,sum);
}