#include <stdio.h>
#define NAME_LEN 20

int main() {
  struct {
	int number;
	char name[NAME_LEN+1];
	int age;
  }student1,student2;

  return 0;
}
