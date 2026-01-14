#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void f(int a, int *c ,  char word0[])
{

}

void decimal(n,M)
{
    int power =0;
    power = pow(M,10);

    if (n>= power)
    {
        printf("error\n");
        return ;
    }
}

int main()
{

    char string[10];
    // 读取
//    scanf("%10s",string);
//    fget(string,sizeof(string),stdin);

    char *DataBase[100] = {};

    printf("%s\n,%zu",string,strlen(string));

    printf("abc vs abd %d",strcmp("abc","abd"));
    
    char word1[20];
    char word0[] = "Kinosci";
    
    strcpy(word1,word0);

    char *wordmove = (char*)malloc(strlen(word0)+1);
    strcpy(wordmove,word0);
    printf("%s",wordmove);

    for (int i = 0;i<sizeof(word0)/sizeof(word0[0]);i++)
    {
        char ch = word0[i];
        putchar(ch);
    }

    //现在我要传入word0

    char *p = strchr(word0,'n');

    char c = *p;
    *p = '\0';

    int M,n;
    if(M<2||M>9||n<0||n !=(int)n)
    {
        printf("");
    }
    void decimal(m,M);




    return 0;
}