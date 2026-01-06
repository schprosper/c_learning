#include <stdio.h>
#define INT_TYPE 0
#define FLOAT_TYPE 1

typedef struct {
	int type; 	//标记字段
	union{
		int i;
		float f;
	}num;
  }Number;

void num_print(Number num);

int main() {
  typedef union{
	int i;
	float d;
  }Number1;

  Number1 num_array[20];
 
  Number n;
  n.type=INT_TYPE; 	//提示修改的是整数
  n.num.i=996;
  num_print(n);
  
  return 0;
}

void num_print(Number num)
{
	if(num.type==INT_TYPE){
		printf("%d\n", num.num.i);
	}
	else{
		printf("%f\n",num.num.f);
	}
}
