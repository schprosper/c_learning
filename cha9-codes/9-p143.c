#include <stdio.h>
#include "a.c"
//#include <a.c>//错误：不能<a.c>，只能"a.c"

int main() {
  printf("i=%d",f(1));
  
  return 0;
}