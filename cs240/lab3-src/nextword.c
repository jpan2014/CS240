
#include <stdio.h>
#include <stdlib.h>

//
// Separates the file into words
//

#define MAXWORD 200
char word[MAXWORD];
int wordLength;

char * nextword(FILE * fd) {
  	char c;
	wordLength = 0;
	while ((c=fgetc(fd)) != EOF)
	{
		if (c != ' ' && c != '\n' && c != '\t' && c != '\r')
		{
			word[wordLength] = c;
			wordLength++;
		}
		else
		{
			if (wordLength > 0)
			{
				word[wordLength] = '\0';
				wordLength = 0;
				return word;
			}
		}
	}
	if (wordLength != 0)
	{
		wordLength = 0;
		return word;
	}
	return NULL;
}

