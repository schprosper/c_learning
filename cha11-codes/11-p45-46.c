#include <stdio.h>

int main() {
  union {
    int i;
    float f;
    char str[10];
  }data={0},u={.f=12.3};

  return 0;
}