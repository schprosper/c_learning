#include <stdio.h>
#include <string.h>

int main() {
    int slen;
	
    slen = strlen("duck"); 	//slen 为 4
	printf("\"duck\"长度=%d\n",slen);

    slen = strlen(""); 		//slen 为 0 
    printf("\"\"长度=%d\n",slen);

	char str1[20];
	strcpy(str1, "cat");
	slen = strlen(str1); 		//slen 为 3 
    printf("str1中的字符串长度=%d\n",slen);

  return 0;
}
