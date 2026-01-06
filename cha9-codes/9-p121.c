/* register.c */
#include <stdio.h>
int fac(int n)
{
	register int i,f=1;
	for(i=2;i<=n;i++)
		f=f*i;
	return(f);
}

int main()
{
	int i;
	for(i=1;i<=10;i++)
		printf("%d!=%d\n",i,fac(i));
}
