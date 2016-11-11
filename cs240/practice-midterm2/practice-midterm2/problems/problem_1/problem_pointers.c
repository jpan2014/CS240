#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Problem (1/4)
/******************************************************************************
 * TODO: Print the array.
 *       The format should be (array index)(colon)(array element)(newline) 
 * 
 * Parameters: n -- the number of elements in the array
 *             array -- a double array
 *
 * Return: void 
 *
 * Return Type: void
 *****************************************************************************/
void printArray(int n, double * array) {
// Write Your Code Here
// gdb mytest, break main, run test1, where/list
	double * d = array;
	int i = 0;
	while (i < n) {
		printf("%d:%lf\n",i, *d);
		i++;
		d++;
	}
}

// Problem (2/4)
/******************************************************************************
 * TODO: Return the minimum element of array 
 * 
 * Parameters: array -- a double array
 *             n -- the number of elements in the array
 *
 * Return: minimum element in array 
 *
 * Return Type: double
 *****************************************************************************/
double minArray(int n, double * array) {
// Write Your Code Here
	double * d = array;
	int i = 0;
	double min;
	min = *d;
	while (i < n)
	{
		if(*d < min) {
			min = *d;
		}
		i++;
		d++;
	}
	return min;
}

// Problem ( 3/4 ) 
/******************************************************************************
 * TODO: Reverse the given string 'str'. 
 * E.g. reverse_str("smile") should return "elims"
 * 
 * Parameters: str -- The given string to be reversed.
 *
 * Return: A pointer to str, str should be reversed 
 *
 * Return Type: char pointer
 *****************************************************************************/
char * reverse_str (char * str ) {
    int len = 0;
    char * copy2 = str;
    char * finish = str;
    while (*copy2) {
	len++;
	copy2++;
    }
    char * copy = str + len - 1;
    copy2--;
    while (str < copy)
    {
	char temp = *copy;
	*copy = *str;
	*str = temp;
	str++;
	copy--;
    }
    return finish;
}

// Problem ( 4/4 ) 
/******************************************************************************
 * TODO: Determine if the string str2 is a permutation of str1. A permutation
 * is the rearranging of characters in a different order. 
 * E.g. the string "act" is a permutation of "cat" 
 *
 * Hint: count the occurences of each letter
 * 
 * Parameters: str1 -- The original string
 *	       str2 -- Determine if this string is a permutation of str1 
 *
 * Return: 1 if str2 is a permutation
 *         0 if str2 is not a permutation
 *
 * Return Type: integer
 *****************************************************************************/
int is_permutation ( char * str1, char * str2 ) {   
    int isPermutation = 1;
    char * copys1 = str1;
    char * copys2 = str2;
    char * copy = str1;
    char * cs1l = str1;
    char * cs2l = str2;
    int len1 = 0;
    int len2 = 0;
    while (*cs1l) {
	len1++;
	cs1l++;
    }
    while (*cs2l) {
	len2++;
	cs2l++;
    }
    //printf("Length of str1 is %d and length of str2 is %d\n", len1, len2);
    if (!(len1 == len2)) {
	isPermutation = 0;
	return isPermutation;
    }
    //printf("I got here though.\n");
    while (*copy)
    {
	//printf("Hello1.\n");
	char * ccopys1 = str1;
	char * ccopys2 = str2;
	char * check = *copy;
    	int counts1 = count(*check, *ccopys1);
	int counts2 = count(*check, *ccopys2);
	printf("Hello.\n");
	printf("Copy is %c and counts1 = %d and counts2 = %d\n", *copy, counts1, counts2);
	if (counts1 == counts2)
		isPermutation = 1;
	else {
		isPermutation = 0;
	}
	copy++;
    }
    return isPermutation;
}

int count(char * counts, char * str2)
{
	int count = 0;
	while (*str2)
	{
		if(strcmp(*counts,*str2) == 0)
			count++;
		str2++;
	}
	return count;
}
