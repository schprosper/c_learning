#include <stdio.h>

int main() {
  char city[][9] = {"Beijing", "Shanghai", "Suzhou" , "Xian", "Chengdu"};
  char *citys[] ={"Beijing", "Shanghai", "Suzhou" , "Xian", "Chengdu"};

  for(int i = 0; i < 5; i ++){
    if(city[i][0] == 'X')
    printf("%s begins with X \n", city[i]);
  }
  printf("%s ", city[1]);
  return 0;
}
