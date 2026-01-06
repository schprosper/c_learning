#include<stdio.h>
int main(){
	char str1[10],str2[10],str3[10];
	int year;
	FILE *fp;
	
    fp=fopen("GoodsInfo.txt","r");
	
    fscanf(fp,"%s %s %s %d", str1, str2, str3, &year);
	
    printf("String1: %s\n",str1);
	printf("String2: %s\n",str2);
	printf("String3: %s\n",str3);
	printf("Integer: %d\n",year);
	
    fclose(fp);
	
    return(0);
}