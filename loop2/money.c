#include <stdio.h>//break只能跳出一次

int main()
{
    int x;
    int one, two, five;

    scanf("%d", &x);  // 输入要凑的金额（单位：元）
    int exit =0;
    for (one = 1; one <= x * 10; one++) {  // 1角最多x*10个（总金额x元=10x角）
        for (two = 1; two <= x * 10 / 2; two++) {  // 2角最多(10x)/2 个
            for (five = 1; five <= x * 10 / 5; five++) {  // 5角最多(10x)/5 个
                // 判断总金额是否等于x元（10x角）
                if (one + two * 2 + five * 5 == x * 10) {
                    printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n", 
                           one, two, five, x);
                           exit = 1;
                           break;
                }
            }if (exit) { break;}
        }if( exit ){break;}
    }
    return 0;
}