#include <stdio.h>
#define NAME_LEN 20

struct Student{
	int number;
	char name[NAME_LEN+1];
	int age;
};

void print_student(struct Student st);

int main() {
  print_student((struct Student){1,"Bob",18});

  struct Student student1=(struct Student){1,"Bob",18};
  print_student(student1);

  return 0;
}

void print_student(struct Student st)
{
	printf("student number:%d\n", st.number);
	printf("student name:%s\n", st.name);
	printf("student age:%d\n", st.age);
}