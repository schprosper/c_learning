#include <stdio.h>
void main(){
    int a;
    a = 6;
    int i,j,k;
    int cnt = 0;

    i = a;
    while (i<= a+3){
        j=a;//让最小位重新来
        while (j<=a+3){
            k = a;
            while (k<=a+3){
                if (i !=j &&i!=k && k!=j)
                {
                    printf("%d%d%d",i,j,k);
                    cnt++;
                    if (cnt == 6){printf("\n");cnt=0;}
                    else {printf(" ");}
                    

            
                }
                
                k++;
            }
            j++;
        }
        i++;
    }

}