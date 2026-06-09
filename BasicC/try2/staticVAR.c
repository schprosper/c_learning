//static

    //实际上 all是全局变量。
    //进来只做一次初始化。

    #include <stdio.h>

int f(void);

int gAll=12;

int main(int argc, char const *argv[])
{
    f();

    return 0;
}

int f(void)
{
    int k=0;
    static int all = 1;
    printf("&gAll=%p\n", &gAll);
    printf("&all=%p\n", &all);
    printf("&k=%p\n", &k);
    printf("in %s all=%d\n", __func__, all);
    all += 2;
    //__func__告诉你函数的名字
    printf("agn in %s all=%d\n", __func__, all);
    return all;
}
/*&gAll=00007FF631FB3000
&all=00007FF631FB3004
在一起
静态全局变量：全局的生存期，本地的作用域*/