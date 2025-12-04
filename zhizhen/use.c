#include <stdio.h>

void minmax(int a[], int len, int *min, int *max);

int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55};
    int min, max;
    printf("mian sizeof(a[])=%lu\n",sizeof(a));
    printf("main a =%p\n",a);
    printf("%p\n%p\n",&a[0],&a[1]);//
    minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
    printf("min=%d,max=%d\n", min, max);
    int *p =&min;
    printf("*p=%d\n",*p);
    printf("p=%p\n",p);
    printf("*a=%d\n",*a);

    return 0;
}

//void minmax(int a[], int len, int *min, int *max)
void minmax(int *a, int len, int *min, int *max)
{//必须留空方括号——其实a[]是个指针，而且也可以写成指针
    int i;
    printf("minmax sizeof(a[])=%lu\n",sizeof(a));
    printf("main a =%p\n",a);
    *min = *max = a[0];
    a[0] = 1000;
    for (i = 1; i < len; i++) {
        if (a[i] < *min) {
            *min = a[i];
        }
        if (a[i] > *max) {
            *max = a[i];
        }
    }
}