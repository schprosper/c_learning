#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 100

int contents[STACK_SIZE];
int top=0;
int *top_ptr = &contents[0];

void make_empty(void);
bool is_empty(void);
bool is_full(void);

void push(int i);
int pop(void);
//void stack_overflow();
//void stack_underflow();

int main() {

  return 0;
}

void make_empty(void)
{
   top = 0;
}

 bool is_empty(void)
 {
   return top == 0;
 }
/*
void stack_underflow()
{
  top = 0;
}
*/
bool is_full(void)
{
    return top == STACK_SIZE;
}

/*
void stack_overflow()
{
  top = STACK_SIZE;
}
*/
void push(int i)
{
    if (is_full())
	    printf(" Stack Overflow "); 
	else
	    contents[top++] = i;
}	

/*
void push(int i) //用指针实现
{
	if (is_full())
		stack_overflow();
	else
		*top_ptr++ = i;
}
*/

int pop(void)
{
	if (is_empty())
	    printf(" Stack Underflow "); 
	else
	    return contents[--top];
}

/*
int pop(void)//用指针实现
{
	if (is_empty())
		stack_underflow();
	else
		return *--top_ptr;
}
*/