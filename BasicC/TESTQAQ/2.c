/* 知识点：
1. 进制转换：十进制转M进制的“除M取余法”核心逻辑；
2. 输入验证：判断M、n是否为整数，M是否在2~9范围内；
3. 数学库函数：<math.h>中pow函数（计算M的10次方）的调用；
4. 错误处理：不符合条件时输出"error"的多条件判断；
5. 循环与分支：实现进制转换的循环、多分支条件判断。
*/
// 题目：十进制数转换为M进制数
// 要求：
// 1. M是2到9之间的整数；
// 2. 先输入M和待转换的数n；
// 3. 若M或n不是整数，输出"error"；
// 4. 若n大于M的10次方，或M不在2~9范围内，输出"error"；
// 5. 符合要求则输出n的M进制形式；
// （M的10次方用<math.h>的double pow(double a, double b)计算，a为M、b为10）
// 样例1：
// 输入：2 a
// 输出：error
// 样例2：
// 输入：3 59050
// 输出：error
// 样例3：
// 输入：2 15
// 输出：1111

# include <stdio.h>
# include <math.h>
void decimal(int n,int M){

    int power = (int)pow(M,10);
    if (M < 2|| M > 9|| n<0||n>= power){
        printf("error\n");
        return ;
    }

    int result[32];
    int idex =0;
    while(n>0){
        result[idex++] = n%M;
        n /=M;
    }
    if(idex==0){
        printf("");
        return;
    }

    int i;
    for (i = idex -1;i>0;i--){
        printf("%d",result[i]);
    }


}
int main ()
{
    printf("请输入：");
    int M,n = 0;
    scanf("%d %d",&n,&M);

    if(M <2 || M>9 || n<0 || n!= (int)n){
        printf("error\n");
        return 0;
    }
    void decimal(n,M);

    
}