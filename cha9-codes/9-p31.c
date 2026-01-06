#include <stdio.h>

int power(int x, int n)
{
	int i, result = 1;
	  for (i = 1; i <= n; i++)
        result = result * x;
	
    return result;
}

/*
int power(int x, int n)
{
	int result = 1;
	  while (n-- > 0)
 	    result = result * x;
	
    return result;
}
*/


int main() {
    int x=3, n=2;
    
    printf("power(%d,%d)=%d",x, n,power(x,n));
    
    return 0;
}
