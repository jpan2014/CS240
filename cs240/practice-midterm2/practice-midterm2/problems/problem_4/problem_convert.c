#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS 32

// Problem (1/2)
/*****************************************************************************
 * TODO: convert a number from the given base to decimal
 *
 * Parameters: number -- the number you are converting an integer
 *             base   -- the base of the number you are given
 * 
 * Return: The number as an integer
 *
 * Return Type: int
*****************************************************************************/
int toInteger(char * number, int base) {
// Write Your Code Here
	//int num = atoi(number);
	int conbase = base;
	char * num = number;
	int index = 0;
	char * copy = num;
	while (*copy) {
		index++;
		copy++;
	}
	index-=1;
	int total = 0;
	while (*num != NULL) {
		if (*num >= 'A') {
			int curr = (*num - 'A' + 10) % conbase;
			total += curr * power(conbase, index);
			index--;
		}
		else
		{
			int curr = (*num - '0') % conbase;
			total += curr * power(conbase, index);
			index--;
		}
		num++;
	}
	return total;
}

int power (int first, int second) {
	if (second == 0)
		return 1;
	return (first*power(first,second-1));
}

// Problem (2/2)
/*****************************************************************************
 * TODO: convert a number from the given base to decimal
 *
 * Parameters: number -- the number you are converting a string
 *             base   -- the base you are converting the numebr to
 * 
 * Return: The number as a string in base "base"
 *
 * Return Type: char *
*****************************************************************************/
char * toBase(int number, int base) {
	int size = 0;
	int numTest = number;
	int num = number;
	while (numTest > 0)
	{
		size++;
		numTest /= base;
	}
	char *str = (char*)malloc(size*sizeof(char));
	int i = size - 1;
	while (num > 0)
	{
		int r = num % base;
		num /= base;
		if ( 0 <= r && r <= 9)
		{
			str[i] = '0' + r;
		}
		else
		{
			str[i] = 'A' + r - 10;
		}
		i--;
	}
	return str;
}
