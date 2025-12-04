#include <stdio.h>
int main (){
    int x=700 ;
    int output=0;
    int middle;
    int nb=0;
    while (x>0){
    nb = x%10;
    printf ("%d",nb);
    x = x/10;

    output = output * 10 + nb;
    //printf ("x=%d,output=%d,nb=%d\n",x,output,nb);
    }

    //printf ("%d",output);

}