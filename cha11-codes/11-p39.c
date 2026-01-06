#include <stdio.h>
#define NAME_LEN 20

struct Student{
	int number;
	char name[NAME_LEN+1];
	int age;
};

void print_student(struct Student st);

int main() {
  struct Student students[100]={{1,"Bob",18}};
  int i=0;
  print_student(students[i]);
  students[i].number=10;
  
  struct Student students1[]={{1,"Bob",18}, {2,"Alice",18}, {3,"Scott",18}, {4,"Jack",19}};

  struct Student students2[100]={[0].number=4,[0].name="Jack",[0].age=19};

  return 0;
}

void print_student(struct Student st)
{
	printf("student number:%d\n", st.number);
	printf("student name:%s\n", st.name);
	printf("student age:%d\n", st.age);
}