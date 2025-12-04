#include <stdio.h>
int main()
{
    int x = 17614;
    int mask = 1 ;
    int t = x;
    while (t>9){
        t= t/10;
        mask *=10;
    }

    do
    {
        int d = x / mask;
        printf("%d ",d);
        x %= mask;
        mask /= 10;
    }while(mask > 0);



}