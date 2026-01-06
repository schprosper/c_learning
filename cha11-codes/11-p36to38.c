#include <stdio.h>

int main() {
  struct Student{
	int number;
	char name[10];
	int age;
	int year;
	int month;
	int day;
  }stu1,stu2;
  
  struct student_birth{
	int year;
	int month;
	int day;
  };

  struct Student_nest{
	int number;
	char name[10];
	int age;
	struct student_birth birthday;
   }student1,student2;

   student1.birthday.year=1996;

  return 0;
}