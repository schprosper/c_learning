#include <stdio.h>

int main() {
      FILE *fp;
    int c;
    fp = fopen ("GoodsInfo.txt","r");
    if(fp == NULL) {
        printf("Error in opening file");
        return(-1);
    }
    while(1) {
        c = fgetc(fp); //从文件指针fp指向的文件中读取一个字符，光标位置后移一个字符
        if( feof(fp) ) {
            break ;}
        printf("%c", c);
    }
    fclose(fp);

  return 0;
}
