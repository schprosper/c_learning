#include <stdio.h>

int main() {
    int hour1, minute1;
    int hour2, minute2;

    // 输入两个时间的时和分
    scanf("%d %d", &hour1, &minute1);
   scanf("%d %d", &hour2, &minute2);

    // 计算小时差和分钟差
    int ih = hour2 - hour1;
    int im = minute2 - minute1;
    if (im < 0) {
        im = 60 + im;
        ih --;
    }

    // 输出时间差
    printf("时间差是%d小时%d分。\n", ih, im);

    return 0;
}