# include <stdio.h>

struct Student
{
    int id;
    float score;
};

int main (void){
    int a = 10;
    int *p = &a;

    printf("a = %d\n",a);
    printf("a = %p\n",(void*)&a);
    printf("p = %p\n",(void*)p);
    printf("*p = %d\n",*p);

    *p = 123;

    print("*p123,then,a = %d",a);

    
}
