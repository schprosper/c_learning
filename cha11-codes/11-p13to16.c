#include <stdio.h>
#define NAME_LEN 20

int main() {
  struct {
	int number;
	char name[NAME_LEN+1];
	int age;
  }student1={1,"Bob",18},student2;
   
  printf("student number : %d\n", student1.number);
  printf("student name : %s\n", student1.name);
  printf("student age : %d\n", student1.age);

  student1.number=2;	
  student1.age++;	
  //scanf("%d",&student1.age);

  student2=student1;

  struct {
	int array[10];
   }a1,b1={{1,2,3,4,5}};
   a1=b1;

  return 0;
}