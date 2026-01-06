#include <stdio.h>
void concatenate(int m, int n, int a[m], int b[n], int c[m+n]);

int main() {
    int m=2,n=3, a[]={1,2}, b[]={3,4,5}, c[m+n],i;
    
    concatenate(m, n, a, b, c);
    
    for (i=0;i<m+n;i++)
      printf("c[%d]=%d\n",i,c[i]);

    return 0;
}

void concatenate(int m, int n, int a[m], int b[n], int c[m+n])
{
  int i;

  for (i=0;i<m;i++)
    c[i]=a[i];

  for (i=0;i<n;i++)
    c[m+i]=b[i];
}
