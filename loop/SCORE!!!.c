//天才！ 完全可以用case结构来
/*大于等于 90 分为 A；
大于等于 80 分且小于 90 分为 B；
大于等于 70 分且小于 80 分为 C
大于等于 60 分且小于 70 分为 D；
小于 60 分为 E；*/

#include <stdio.h>
int main (){
    int grade;
    int first;
    scanf ("%d",&grade);
    first = grade / 10;

    switch  (first)  {
        case 10 :
        case 9 :
        printf ("A");
        break;
        case 8 :
        printf ("B");
        break;
        default :
        printf("C");
        // 但是没有单一出口原则

    }
    return 0 ;
}