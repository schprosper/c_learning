#include <stdio.h>
#include <string.h>

#define NAME_LEN 20

struct Student{
	int number;
	char name[NAME_LEN+1];
	int age;
};

void print_student(struct Student st);
struct Student build_student(int number,const char* name,int age);

int main() {
  struct Student st1={1,"Bob",18},st2;
  print_student(st1);
  
  st2 = build_student(2,"Jerry",20);
  print_student(st2);

  return 0;
}

void print_student(struct Student st)
{
	printf("student number:%d\n", st.number);
	printf("student name:%s\n", st.name);
	printf("student age:%d\n", st.age); 
}

struct Student build_student(int number,const char* name,int age)
{
	struct Student st;
	
    st.number=number;
	strcpy(st.name,name);
	st.age=age;
	
    return st;
}

