#include <stdio.h>

int main() {
    int n;
    int fact = 1 ;
    scanf ("%d",&n);
    int i = n;
    // for (int i=1;i<=n;i++){
    //     fact *=i;
    // }
    for ( ;n>1;n--){fact  *= n;}
    printf("%d! = %d\n", i, fact);
    return 0;
}
//任何for都可以写成while