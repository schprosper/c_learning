# include <stdio.h>
# include <stdbool.h>


typedef int ElemType;
typedef struct 
{
    ElemType data;
    int height;
} Man ;

struct Student
{
    int id;
    float score;
};

int main (void){
    int a = 10;
    int *p = &a;

    Man fake;
    fake.data = 1;
    Man *big;
    big->data;
    
    

    printf("a = %d\n",a);
    printf("a = %p\n",(void*)&a);
    printf("p = %p\n",(void*)p);
    printf("*p = %d\n",*p);
    printf("%p\n",a);

    *p = 123;

    printf("*p123,then,a = %d",a);

    
}



