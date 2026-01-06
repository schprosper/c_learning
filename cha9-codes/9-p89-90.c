#include <stdio.h>
int f();
void g(int x);
void h();

int main() {
  f();
  return 0;
}

int f()
{
  g(0);
  return 1;
}

void g(int x)
{
  return;	
}

void h()
{
  h();//递归
}


