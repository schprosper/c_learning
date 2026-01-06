#include <stdio.h>
#include <stdlib.h>

void main(){
    char c;
    
    for(c=65; c <=122; c ++){
        if(c > 90 && c < 97)
            continue;
        printf("%4d -- %c\n ", c, c);
    }
    
    printf("\n");
}
