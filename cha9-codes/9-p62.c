#include <stdio.h>
int main(int argc, char *argv[])
{
	int i,*p=&i;
	
	printf("Enter a number: ");
	//scanf("%d", &p);  //WRONG，读入的数被存在p中而不是i中，危险
	scanf("%d", p); //正确

	printf("i=%d\n",i); 

	return 0;
}
