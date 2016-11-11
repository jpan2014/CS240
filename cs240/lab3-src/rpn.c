
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

#include "rpn.h"
#include "nextword.h"
#include "stack.h"

double rpn_eval(char * fileName, double x) {
	FILE * fd = fopen(fileName, "r");
	char * word;
	double currentNumber;
	double previousNumber;
	double hold;
	while ((word = nextword(fd)) != NULL)
	{
		if (*word == 'x')
		{
			stack_push(x);
		}
		else if (strcmp(word,"+") == 0)
		{
			currentNumber = stack_pop();
			previousNumber = stack_pop();
			hold = (currentNumber + previousNumber);
			stack_push(hold);
		}
		else if (strcmp(word,"-") == 0)
		{
			currentNumber = stack_pop();
			previousNumber = stack_pop();
			hold = ((previousNumber) - (currentNumber));
			stack_push(hold);
		}
		else if (*word == '*')
		{
			currentNumber = stack_pop();
			previousNumber = stack_pop();
			hold = ((previousNumber*1.0) * (currentNumber*1.0));
			stack_push(hold);
		}
		else if (*word == '/')
		{
			currentNumber = stack_pop();
			previousNumber = stack_pop();
			hold = ((previousNumber*1.0)/(currentNumber*1.0));
			stack_push(hold);
		}
		else if (strcmp(word, "sin") == 0)
		{
			currentNumber = stack_pop();
			stack_push(sin(currentNumber*1.0));
		}
		else if (strcmp(word, "cos") == 0)
		{
			currentNumber = stack_pop();
			hold = cos(currentNumber*1.0);
			stack_push(hold);
		}
		else if (strcmp(word,"pow") == 0)
		{
			currentNumber = stack_pop();
			previousNumber = stack_pop();
			hold = pow(previousNumber, currentNumber);
			stack_push(hold);
		}
		else if (strcmp(word,"log") == 0)
		{
			currentNumber = stack_pop();
			hold = log(currentNumber);
			stack_push(hold);
		}
		else if (strcmp(word,"exp") == 0)
		{
			currentNumber = stack_pop();
			hold = exp(currentNumber);
			stack_push(hold);
		}
		else
		{
			stack_push(atof(word));
		}
	}
	if (stack_top() == 1)
	{
		double result = stack_pop();
		return result;
	}
	else
	{	
		printf("Elements remain in the stack\n");
		exit(1);
	}
}

