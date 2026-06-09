#include <stdio.h>//水仙花数
void main(){
    //遍历三位数
    int n;
    n = 3;
    int i =1;
    int first = 1;
    while(i<n){
        first *=10;
        i++;
    }
    i = first;//让i成为被记录的三位数
    while (i < first*10){
        int t = i;
        int d =0;
        int sum = 0;
        do{
            d = t%10;
            t /= 10;
            int p = 1;
            int j =0 ;
            while (j<n){
                p *=d;
                j++;
            }
            sum +=p;
            
        }while (t >0);
        if (sum == i){printf("%d\n",i);}

        
        i++;
    }

}