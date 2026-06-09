#include <stdio.h>
int main (void){
    printf("输入一个四位数:");
    int number;
    scanf ("%d", &number);

    int one;
    int two;
    int three;
    int four;

    one = number % 10;
    two = number % 100 / 10;
    three = number % 1000 / 100;
    four = number / 1000;

    int anti_number;

    anti_number = one* 1000 + two*100 + three *10 + four *1;

    printf ("我倒过来了：%d", anti_number);

    return 0;

}
