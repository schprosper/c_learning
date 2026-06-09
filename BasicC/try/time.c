#include <stdio.h>
int main(void){
    int time = 0; 
    int past = 0;
    
    printf("输入现在的时间（空格)过去的分钟数：");
    scanf ("%d %d", &time , &past);

    int time_min;
    int time_final;
    time_min = time/100*60 + time%100;// 这里是对time取余100！！！
    time_final = time_min + past;
    
    int output;
    int h; 
    int min;
    
    h = time_final / 60;
    min = time_final % 60 ;
    output = h*100 + min;

    printf("现在的时间是：%d", output );
    return 0;
}
