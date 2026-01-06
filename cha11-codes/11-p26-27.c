#include <stdio.h>
#define NAME_LEN 20

int main() {
  typedef struct{
	int number;
	char name[NAME_LEN+1];
	int age;
  }Student;
  
  Student student1,student2;

  return 0;
}