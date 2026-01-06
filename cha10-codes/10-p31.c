#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 80
void main(){
    char string1[STR_LEN+1], string2[STR_LEN+1];
    int i;
    
    printf("Please input the string: \n");
    scanf("%s", string2);
    
    for(i = 0; string2[i] != '\0'; i ++){
        string1[i] = string2[i];
    }
    
    string1[i] = '\0';
    
    printf("%s \n", string1);
    printf("the len of character is  %d \n", i);
}
