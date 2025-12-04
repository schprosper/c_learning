#include <stdio.h>
#define HH 3
int main (){
    const int CC ;//你没给cc赋值好吧。。。
    const int gugugaga = 4;//const int 定义的是「只读变量」
                        //不是真正的编译时常量

    enum { hello = 4 };  // 枚举常量是编译时常量
    int type ;

    scanf ("%d",&type );

    switch (type){
        case 1 :
        printf ("nihao");
        default :
        printf ("gun");
        
        case HH :
        printf("good morning");
        break;
        case hello  :
        printf ("hello");
        break;
        case (hello + 1)  :
        printf ("papa");
        break;
        
    }
    return 0;
}