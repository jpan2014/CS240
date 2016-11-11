#include <stdio.h>
#include <stdlib.h>
#include "review.h"

// Problem (1/4)
/******************************************************************************
 * TODO: Compare the first 'n' bytes of s1 and s2. Return 1 if s1 is greater 
 * than s2. Return -1 if s1 is less than s2. Return 0 if the strings are equal.
 * 
 * Parameters: s1 -- string to be compared
 *             s2 -- string to be compared
 *             n -- compare the first 'n' bytes of s1 and s2
 *
 * Return: 1 if s1 is greater than s2
 *         -1 if s1 is less than s2
 *         0 if the strings are equal
 *
 * Return Type: integer
 *****************************************************************************/
int strncmp(const char *s1, const char *s2, size_t n) 
{
    // Write Your Code Here
    int i;
    for (i = 0; i < n; i++) {
    	if (*s1 > *s2) { 
    		return 1;
    	}
    	else if (*s2 > *s1) { 
			return -1;
		}
    	else { 
    		if (i == n-1) {
    			return 0;
    		}
    	}
    	s1++;
    	s2++;
    }
    return 0;
}

// Problem (2/4)
/******************************************************************************
 * TODO: Allocate memory for 'sub_n' integers. Store the 'sub_n' smallest 
 * integers of the array in the newly allocated space. You can assume there is 
 * at least 'sub_n' elements in the array and all the elements are unique. 
 * The array returned should be in sorted order. Return a pointer to the array.
 *
 * ex. array = {5, 2, 1} 
 *     n = 3
 *     sub_n = 2
 *     sub_min_array(array, n, sub_n) should return {1, 2} because 1 and 2
 *     are the two smallest elements in the array
 * 
 * Parameters: array -- an integer array
 *             n -- the number of elements in the array
 *             sub_n -- number of integers in the newly allocated sub array
 *
 * Return: an array of the 'sub_n' smallest elements in the array.
 *
 * Return Type: integer pointer
 *****************************************************************************/
int * sub_min_array( int * array, int n, int sub_n ) 
{
    // Write Your Code Here
//    int * newer = int*[n];
//    int i;
//    for (i = 0; i < n; i++) {
//    		newer[i] = *array;
///    		array++;
//    }
//    return *newer;
	return NULL;
}

// Problem (3/4)
/******************************************************************************
 * TODO: Print the bits of the unsigned integer as 0s and 1s.
 * 
 * Parameters: bitmap -- print the unsigned integer in binary format
 *
 * Return: void
 *
 * Return Type: void
 *****************************************************************************/
void print_bits( unsigned int bitmap ) 
{
    // Write Your Code Here
    int i;
    for (i = (sizeof(bitmap) * 8)-1; i >= 0; i--) {
    	printf("%d", ((bitmap >> i) & 1));
    }
    printf("\n");
}

// Problem (4/4)
/******************************************************************************
 * TODO: Insert a new node to the end of the single linked list. Set the value
 * of the new node equal to the value of the parameter 'value'. 
 *
 * Check mytest.c and review.h for linked list implementation.
 *
 * Parameters: list -- insert the new node in to this single linked list
 *             value -- set the value of the new node equal to this
 *
 * Return: void
 *
 * Return Type: void
 *****************************************************************************/
void llist_insert_last( List * list, int value ) 
{
    // Write Your Code Here
}
