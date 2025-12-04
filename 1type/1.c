#include <stdio.h>
int main()
{
   float a, b, c;
a = 1.345;
b = 1.123;
c = a + b;
if (c == 2.468)
    printf("相等\n");
else
    printf("不相等! c=%.10f，或%f\n", c, c);
}