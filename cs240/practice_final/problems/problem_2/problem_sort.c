#include "sort.h"
#include <alloca.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Problem (1/1)
/******************************************************************************
 * TODO: Sort an array of elements of any type. Use the 'compFunc' to sort the
 * elements. 
 *
 * Parameters: n -- number of elements in the array
 *             elementSize -- the size of each element
 *             array -- pointer to an array of arbitrary size
 *             ascending -- 
 *             compFunc -- the comparison function
 *
 * Return: void
 *
 * Return Type: void
 *****************************************************************************/
void mysort(int n, int elementSize, void * array, int ascending, CompareFunction compFunc)
{
	// Write Your Code Here
	void * temp = malloc(n);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			void *e1 = (void*)(char*)array+j*elementSize;
			void *e2 = (void*)(char*)array+(j+1)*elementSize;
			if (ascending == 1) {
				if(compFunc(e1, e2) > 0)
				{
					memcpy(temp, e1, elementSize);
					memcpy(e1, e2, elementSize);
					memcpy(e2, temp, elementSize);
				}
			}
			else {
				if(compFunc(e1, e2) < 0)
				{
					memcpy(temp, e1, elementSize);
					memcpy(e1, e2, elementSize);
					memcpy(e2, temp, elementSize);
				}
			}
		}
	}
	free(temp);
}

int compInt(void * a, void * b)
{
	int * p1 = (int *) a;
	int * p2 = (int *) b;
	if (*p1 > *p2)
	{
		return 1;
	}
	else if (*p1 < *p2)
	{
		return -1;
	}
	else {
		return 0;
	}
}

int compStr (void * a, void * b)
{
	char ** p1 = (char **) a;
	char ** p2 = (char **) b;
	if (strcmp (*p1, *p2) > 0)
	{
		return 1;
	}
	else if (strcmp(*p1, *p2) < 0)
	{
		return -1;
	}
	else {
		return 0;
	}
}

