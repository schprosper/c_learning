#include <stdio.h>
#define NAME_LEN 20

int main() {
  struct Student {
	int number;
	char name[NAME_LEN+1];
	int age;
  };
  
  struct Student student1,student2;
  
  char Student[10];

  return 0;
}