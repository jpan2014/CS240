#include <stdio.h>

// Problem (1/2)
/******************************************************************************
 * TODO: Print each number in succession from low to high
 *       E.g. printRange(1, 4) should print
 *       1, 2, 3, 4
 * 
 * Parameters: low -- the starting range
 *             high -- the ending range
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void printRange(int low, int high) {
	if (high <= low)
	{
		printf("Error: Invalid value for upper bound.\n");
	}
	else
	{
		int i;
		for (i = low; i<high; i++)
		{
			printf("%d, ", i);
		}
		printf("%d\n", high);
	}
}


// Problem ( 2/2 ) 
/******************************************************************************
 * TODO: Print each character of the string 'str' on a seperate line. 
 *       E.g. printString("cat") should print
 *       c
 *       a
 *       t
 * 
 * Parameters: str -- the string you will be printing
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void printString(char * str) {
    char * older = str;
    while(*older)
    {
    	printf("%c\n", *older);
	older++;
    }
}
