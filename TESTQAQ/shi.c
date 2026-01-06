#include <stdio.h>

void main(){
    // int a = 1;
    // float b = a +1;
    // printf("a = %d\n ,&b = %p\n",a,(void*)&b);
    
    // scanf("%d,%d",&a,&b);
    // printf("a++= %d\n , ++a = %d \n,b = %.4f\n",a++, ++a,b);

    // int i = 0;
    // if (i >10 ) {
    //     //优先级：仅大于赋值
    //     i ++;
    //     printf("i =%d\n",i);
    // }
    // else if(0){;}
    // else if(0){;}
    // else {;}

    // do
    // {
    //     i ++;
    //     printf("i = %d\n",i);
    // } while (i < 10);




    // int test = 2;
    // switch (test)
    // {
    // case 1:
    //     printf("fail\n");
    //     break;
    // case 2 :
    //     printf("not fail\n");
    // default:
    //     printf("switch wrong\n");
    //     break;
    // }


    // for (i = 0;i<10 ;i++)
    // {
    //     if (i == 3){
    //         continue;
    //     }
    //     printf("i=%d\n",i);
    // }
    int i = 0;
    printf ("sizeof = %zu\n",sizeof(i));
    
    printf ("sizeof = %zu\n",sizeof((double)i));
    char c = 'B' ;

    int m = 70;

    if (m>='A'&& m <='Z')
    {
        printf("大写字母%c",m);
    }

    int age = 19;

    if (!(age>=18))
    {printf("%d",age);}
    




    
    

    

}