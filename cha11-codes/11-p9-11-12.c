#include <stdio.h>
#define NAME_LEN 20

int main() {
  struct {
	int number;
	char name[NAME_LEN+1];
	int age;
  }student1={1,"Bob",18};

  struct {
	int number;
	char name[NAME_LEN+1];
	int age;
  } student2={.number=1, .name="Bob", .age=18}
    ,student3={.number=1, "Bob", .age=18};

  return 0;
}