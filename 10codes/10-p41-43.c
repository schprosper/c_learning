#include <stdio.h>
# include <string.h>

int main() {
  char city[10], city2[20],city3[20];
  
  strcpy(city, "Chengdu");
  printf("%s\n",city);

  strcpy(city2, city);
  printf("%s\n",city2);
  
  strcpy(city3, strcpy(city, "Chengdu"));
  printf("%s",city3);

  return 0;
}