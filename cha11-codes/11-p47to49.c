#include <stdio.h>
#define NAME_LEN 20

int main() {
  struct person{
	int age;
	char name[NAME_LEN+1];
	int person_type;
	int stdudent_number;
	int grade;
	int teacher_number;
	int class_number;  
  };

  struct person_union{
	int age;
	char name[NAME_LEN+1];
	int person_type;
	
    union{
		struct {
		   int student_number;
		   int grade; 
		} student;
		struct {
		   int teacher_number;
		   int class_number;
		} teacher;
	} per;
  } c ={25,"Bob",0,{1,2}};
  
  printf("%d\n", c.per.student.student_number);

  return 0;
}