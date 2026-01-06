#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 80
void main(){
    char line[STR_LEN + 1], tmp;
    int i = 0;

    printf("Please input text, press <return> key at end: \n");
    
    do{
        tmp = getchar();
        line[i]  = tmp;
        i ++;
    }while(tmp != '\n');

    i -= 1;
    line[i] = '\0';

    printf("%s \n", line);  
}
