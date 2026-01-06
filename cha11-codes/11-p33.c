#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>

#define NAME_LEN 20

struct Student{
	int number;
	char name[NAME_LEN+1];
	int age;
};

void print_student(struct Student *st);
struct Student* build_student(int number,const char* name,int age);

int main() {
  struct Student st={1,"Bob",18};
  struct Student *st_point=&st;

  print_student(st_point);
  
  st_point=build_student(2,"Marry",19);
  print_student(st_point);

  return 0;
}

void print_student(struct Student *st)
{
	printf("student number:%d\n", st->number);
	printf("student name:%s\n", st->name);
	printf("student age:%d\n", st->age);
}

struct Student* build_student(int number,const char* name,int age)
{
	struct Student *st;
	st=(struct Student *)malloc(sizeof(struct Student));
	st->number=number;
	strcpy(st->name,name);
	st->age=age;
	return st;
}

