#include <stdio.h>
#include <stdlib.h>
// *a 是取指针指向的值
void swap(int *a , int *b)
{
    int c = 0;
    c = *a ;
    *a = *b ;
    *b = c ;
    
}

void main()
{
    // int a = 1;
    // int b = 2; 
    // swap(&a,&b);//所以这里必须传入地址
    // printf("交换后:a=%d, b=%d\n", a, b);

    // int num = 100;
    // int number[num];
    // //定义的时候是长度，使用的时候是取用值
    // int i = 0;
    // for (i=0;i<sizeof(number)/sizeof(number[0]);i++){
    //     number[i] = 0;
    //     printf("第%d个是:%d\n" ,i , number[i]);
    // }

    // *p 是转义p
    int i = 10;
    int *p = &i;
    printf("%p,%d\n",p,*p); 
    //00000000005FFE74,000000000000000A 所以 *p是指向他的值

//*后面跟const → 指针本身（纸条）不能变；
//*前面跟const → 指针指向的内容（盒里的东西），不能通过这个指针改。

    int a [30]={1,1,1,1,1,1,1,1,1,1};


    for (i=0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("第%d个是:%d\n" ,i ,a[i]);
 
    }

}