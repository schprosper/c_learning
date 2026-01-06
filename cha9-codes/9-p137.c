#include <stdio.h>
int i;
void f(int i);
void g( void);
void h( void);

int main() {
  
  return 0;
}

void f(int i)
 {
   i=1;
 }

void g( void)
{
   i=2;

   if (i>0){
     int i;
     i=3;
   }

   i=4;
}

void h( void)
{
    i=5;
}