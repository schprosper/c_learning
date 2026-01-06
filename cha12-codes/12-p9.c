#include <stdio.h>
int main () {
    FILE *fp;
    
    fp = fopen ("GoodsInfo.txt ","w");
    
    if(fp == NULL) {
        perror("Error in opening file");
        return(-1);
    }
    
    fprintf(fp, "%s %s %s %d", "we", "are", "in", 2019);
    
    fclose(fp);
    
    return(0);
}