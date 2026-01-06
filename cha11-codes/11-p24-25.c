#include <stdio.h>
#define NAME_LEN 20

int main() {
  struct Student {
	int number;
	char name[NAME_LEN+1];
	int age;
  }student1={1,"Bob",18},student2;

  student2=student1;
  
  return 0;
}