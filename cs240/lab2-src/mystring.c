
#include <stdlib.h>
#include "mystring.h"

// Type "man string" to see what every function expects.

int mystrlen(char * s) {
	int len;
	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return len;
}

char * mystrcpy(char * dest, char * src) {
	char * older = src;
	char * newer = dest;
	while (*older)
	{
		*newer = *older;
		newer++;
		older++;
	}
	*newer = '\0';
	return dest;
}

char * mystrcat(char * dest, char * src) {
	char * older = src;
	char * newer = dest;
	while (*newer)
	{
		newer++;
	}
	while (*older)
	{
		*newer=*older;
		older++;
		newer++;
	}
	*newer = '\0';
	return dest;
}

int mystrcmp(char * s1, char * s2) {
	if (mystrlen(s1) == mystrlen(s2))
	{
		return 0;
	}
	else if (mystrlen(s1) > mystrlen(s2))
	{
		return 1;
	}
	return -1;
}

char * mystrstr(char * hay, char * needle) {
	while (*hay)
	{
		char * p = hay;
		char * q = needle;
		while (*p && *q && *p == *q)
		{
			p++;
			q++;
		}
		if (*q == '\0')
		{
			return hay;
		}
		hay++;
	}
	return NULL;
}

char * mystrdup(char * s) {
	char * newer = (char*)malloc((mystrlen(s))*sizeof(char*));
	char * rnewer = newer;
	char * hold = s;
	while (*hold)
	{
		*newer = *hold;
		hold++;
		newer++;
	}
	newer = '\0';
	return rnewer;
}

char * mymemcpy(char * dest, char * src, int n)
{
	char * newer = dest;
	//*dest = mystrdup(src);
	//char * newer = (char*)malloc(n*sizeof(char*));
	char * rnewer = newer;
	char * hold = src;
	int ph = 0;
	while ((ph < n) && *hold)
	{
		*newer = *hold;
		hold++;
		newer++;
		ph++;
	}
	newer = '\0';
	return rnewer;
}

