# include <stdio.h>

enum Week {Mon,Tue,Wed,};

struct kaqi
{
    char name[20];
    int age;
    float score;
};


int main ()
{

    enum Week Today = Wed;
    if (Today == Wed )
    {
        ;
    }

    struct kaqi k = {"hellp",18,19.5};

    printf("%s",k.name);
    

    union nim
    {
        int a ;
        char c;
    };
    
}

// 输入字母or变量，自动得到数字对应。


