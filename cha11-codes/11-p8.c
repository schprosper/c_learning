#include <stdio.h>
#define NAME_LEN 20

int main() {
  struct {
	int number;				//学生学号
	char name[NAME_LEN+1];		//学生姓名
	int age;				//学生年龄
  }student1;

  struct {
	int id;					//教室工号
	char name[NAME_LEN+1];		//教师姓名
	int age;				//教师年龄
  }teacher1;
  
  int age;

  return 0;
}