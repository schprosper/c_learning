#include <stdio.h>

void print_one_row(void);
void print_all_rows(void);

int main(int argc, char *argv[])
{
	print_all_rows();
}

void print_all_rows(void)
{
	for (int i = 1; i <= 10; i++) {
	    print_one_row();
	    printf("\n");
	}
}

void print_one_row(void)
{
	for (int i = 1; i <= 10; i++)
	    printf("*");
}