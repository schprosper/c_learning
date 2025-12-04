#include <stdio.h>
#include <stdlib.h>

void main(){
    char subject[20] = "Computer Science";
    
    printf("------------------------------\n");
    printf("%s\n", subject);
    //printf("%10.4s\n", subject);
    //printf("%-10.4s\n", subject);
    printf("%18s\n", subject);
    printf("%5s\n", subject);
    printf("%16.8s\n", subject);
    printf("%-16.8s\n", subject);
    printf("%16.0s\n", subject);
    printf("%.3s\n", subject);
    printf("------------------------------\n");
}
