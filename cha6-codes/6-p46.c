#include <stdio.h>

int main() {
  int d, n;
  
  printf("输入判断的整数：");
  scanf("%d", &n);
  
  if (n<=1) {
    printf("请输入大于1的整数:");
    scanf("%d", &n);
  }

  for(d = 2;  d < n; d++)     
    if (n % d == 0)
      goto done;
  
  done:
  if (d < n)
    printf("%d整除%d\n", n, d);
  else
    printf("%d是素数\n",n);
  
  return 0;
}