
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int top=0;
double stack[MAXSTACK];

void stack_clear() 
{
  top = 0;
}

double stack_pop()
{
	if (top == 0)
	{
		printf("Stack underflow\n");
		exit(1);
	}
	top--;
	return stack[top];
}

void stack_push(double val)
{
	if (top >= 100)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	stack[top] = val;
	top++;
}

void stack_print()
{
	printf("Stack:\n");
	if (stack_is_empty() == 1)
	{
		printf("Stack is empty");
	}
	else
	{
		int n;
		n = 0;
		while (n < top)
		{
			printf("%d: %f\n", n, stack[n]);
			n++;
		}
	}
}

int stack_top()
{
  return top;
}

int stack_max()
{
  return MAXSTACK;
}

int stack_is_empty()
{
  return top == 0;
}


