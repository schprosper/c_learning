#include <stdio.h>
#define STR_LEN 80

int main() {
  int size=6;
  char string_name[size];

  char s[8] = "network";
  char subject[5] = "math";
  char subject1[5] = {'m', 'a', 't', 'h', '\0'};


  char location[STR_LEN + 1];
  char location1[] = {'c', 'h', 'e', 'n', 'g', 'd', 'u', '\0'};
  char subject2[5] = {'m', 'a', 't', 'h', '\0'};

  //char subject3[3] = "math";//不合法:数组的大小声明得比初始化的字符小

  char s1[4] = "abc";
  char s2[4];
  //s2 = s1;//不合法:数组名不能用做赋值运算符的左操作数

  return 0;
}