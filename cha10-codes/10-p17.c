#include <stdio.h>
#include <stdlib.h>

int main(){
    char subject[ ]= "Computer";

    for(int i = 1; i < 9; i ++){
        printf("%12.*s \n", i, subject);
    }
    for(int i = 8; i >=1; i --){
        printf("%12.*s \n", i, subject);
    }

    for(int i = 1; i < 9; i ++){
        printf("%.*s \n", i, subject);
    }
    for(int i = 8; i >=1; i --){
        printf("%.*s \n", i, subject);
    }

    for(int i = 1; i < 9; i ++){
        printf("%*.1s \n", i, subject);
    }
    for(int i = 8; i >=1; i --){
        printf("%*.1s \n", i, subject);
    }
}