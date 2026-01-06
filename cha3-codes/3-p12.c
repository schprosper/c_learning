/* volume.c */
#include <stdio.h>
int main(void)
{
    int length, volume;   		 // Variables declarations.
    length = 9;			 //立即数
    volume = length * length * length;	 //Computing
    printf("The length of one side of the cube: %d\n", length);     // Output
    printf("The volume of the cube: %d\n", volume);	            //Output
    return 0;
}
