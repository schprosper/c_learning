#include <stdio.h>

int main() {
  enum {PENCIL,PEN} box1;
  //PENCIL=1; //错误:不能进行普通的算术赋值
  //printf("%d",sizeof(box1));

  enum Box {PENCIL1=3,PEN1=4};
  enum Box box2;
  
  typedef enum {PENCIL2,PEN2} Box;
  Box s1,s2;

  typedef struct {
	enum {INT_TYPE,FLOAT_TYPE}type; 	//标记字段
	union{
			int i;
			float d;
	}u;
  }Number;


  return 0;
}
