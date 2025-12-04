//输入输出，做运算
#include <stdio.h>

void  main(){
    int give = 0;//必须先定义变量
    printf("输入你多少钱");
    scanf("%d", &give );
    const int amount = give;//给你个名字，很容易找到100，const 不能被修改
    int price = 0 ;//**变量，类型是int，初始值是03**
    // =赋值 
    // 变量首先要初始化才能备用
    //类型，名称 = 初始值

    printf("输入金额（元）");
    scanf("%d", &price);//接受外来信息
//读入证书，读的结果赋值给变量price

    int change = amount - price;
    printf("找您%d元\n", change);
}