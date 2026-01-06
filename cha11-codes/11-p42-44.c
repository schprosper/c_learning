#include <stdio.h>

int main() {
  union {
	int i;
   	float f;
   	char str[10];
  } data;
    
  data.i=20;
  data.f=15.2;

  return 0;
}
