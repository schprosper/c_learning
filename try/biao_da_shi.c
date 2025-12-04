//运算符（+-*），算子（变量或者 常数）
#include <stdio.h>
void main(){
    int hour1, minute1;
    int hour2, minute2;
    printf("第一个时间：");
    scanf("%d %d", &hour1, &minute1);

    scanf("%d %d", &hour2, &minute2);


    int time1 = hour1 * 60 + minute1;

    int time2 = hour2 * 60 + minute2;

    int t = time2 - time1;

    printf("时间差是%d小时%d分。", t / 60, t % 60);
}
// 问题解决的过程中需要什么数据，我需要怎么保存它