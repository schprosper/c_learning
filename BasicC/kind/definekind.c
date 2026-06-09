//摆脱 struct point i = {}
//
#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   char  str[20];
};
 
int main( )
{
   union Data data,m;        
 
   printf( "Memory size occupied by data : %d\n", sizeof(m));
 
   return 0;
}