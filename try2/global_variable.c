/*


*/
#include <stdio.h>
int gAll = 15;//自动补上0值
int f();

int main()
{
    printf("%s,%d\n",__func__,gAll);
    f();
    printf("%s,%d\n",__func__,gAll);
    return 0 ;
    
}

int f(void)
{
    printf("%s,%d\n",__func__,gAll);
    gAll++;
    printf("%s,%d\n",__func__,gAll);
    return gAll;
}