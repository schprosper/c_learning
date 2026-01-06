#include <stdio.h>
int power(int x, int n)
{
    int result = 1;
    while (n-- > 0)
        result = result * x;
        return result;
}

void main()
{
    int i=2,j=8;
    printf("%d power %d equal to %d\n",i,j,power(i,j)) ;
}
