#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Problem ( 1/3 ) 
/******************************************************************************
 * TODO: Count the number of lines in the file named 'fileName'. Return the 
 * number of lines as an integer.
 * 
 * Parameters: fileName -- name of the file
 *
 * Return: number of lines in the file
 *
 * Return Type: integer
 *****************************************************************************/
int countLines(char * fileName) {
    int lines;
    lines = 0;
    FILE * fd = fopen(fileName, "r");
    if (fd == NULL)
    {
    	printf("Could not open file %s\n", fileName);
	exit(1);
    }
    char c;
    while ((c=fgetc(fd)) != EOF)
    {
    	if (c == '\n')
	{
		lines++;
	}
    }
    return lines;
}

// Problem ( 2/3 ) 
/******************************************************************************
 * TODO: Read the text file, parse each word, and store the word in to the
 * 'word_list'. Change all the characters in the word to capital letters. 
 * Return 'word_list'.
 *
 * E.g. a text file contains "Hello, world"
 *      The string array 'word_list' should contain {"HELLO", "WORLD"}
 * 
 * Parameters: fileName -- name of the file
 *             word_list -- seperate the words from the text file and store
 *             each word in to this string array. Make sure to change all the
 *             characters in the word to upper case.
 *
 * Return: return the string array 'word_list'
 *
 * Return Type: char double pointer (String array)
 *****************************************************************************/
int my_strlen(char * s)
{
int len = 0;
while (*s)
{
	len++;
	s++;
}
return len;
}

char * my_strdup(char * s)
{
	char * copy = (char*)malloc((my_strlen(s)*sizeof(char*)));
	char * copied = copy;
	while (*s)
	{
		*copy = *s;
		copy++;
		s++;
	}
	copy = '\0';
	return copied;
}	

char ** create_word_list( char * fileName, char ** word_list ) {
    int pos = 0;
    FILE * fd = fopen(fileName, "r");
    char holder[200];
    if (fd == NULL)
    {
    	printf("Could not open file %s\n", fileName);
	exit(1);
    }
    char c;
    int separate = 0;
    while ((c=fgetc(fd)) != EOF)
    {
    	if (c != ' ' && c != '\n' && c != '\r' && c != '\t' && c != ',' && c!= '.' && c!='-')
	{
		if (c >= 'a' && c <= 'z')
			c=(c-'a'+'A');
		holder[pos] = c;
		pos++;
		c++;
	}
	else {
		if (pos > 0)
		{
			holder[pos]='\0';
			pos = 0;
			word_list[separate] = my_strdup(holder);
			separate++;
		}
		c++;		
	}
    }
    return word_list;
}

// Problem ( 3/3 ) 
/******************************************************************************
 * TODO: Iterate through the list of words in each file. If a word is found in
 * both files, add the word to 'match_list'. Do not repeat words in the list. 
 * Capitilization of words does not matter. So "Bob" and "bob" should be
 * considered a match. When inserting the word in to the list, make all the
 * characters in the word upper case. 
 *
 *  HINT: Use the function create_word_list to save time.
 *
 * E.g. File1 contains the text "We like fruit. It is good."
 *      File2 contains the text "Fruit is very delicious."
 *
 *      The string array 'match_list' should contain {"FRUIT", "IS"}
 *
 * Parameters: fileName1 -- name of the first text file
 *	       fileName2 -- name of the second text file
 *	       match_list -- store the intersecting words from both files in
 *	                     this string array. 
 *
 * Return: Return the string array 'match_list'.
 *
 * Return Type: char double pointer (String array)
 *****************************************************************************/
int contains (char * word, char ** listThing)
{
	int pos;
	return contains(word, listThing[pos++]);
}


char ** sharedWords( char * fileName1, char * fileName2, char ** match_list ) {
    char ** hold1 = (char**)malloc(200*sizeof(char*));
    char ** hold2 = (char**)malloc(200*sizeof(char*));
    char ** hold3 = create_word_list(fileName1, hold1);
    char ** hold4 = create_word_list(fileName2, hold2);
    int i,j,k,len=0;
    char * c;
    char ** hold5 = match_list;
    while (hold3[i] != NULL) {
    	c = hold3[i];
	printf("%s\n",c);
	while (hold4[j] != NULL){
		if (c != NULL && strcmp(c, hold4[j]) == 0){
			//printf("HELLO%s\n",hold4[j]);
			int contain = contains(*c, match_list);
			/*k = 0;
			while(k <= len)	{
				if (strcmp(c,hold5[k]) == 0)
					k++;
				else if (len == k){
					if (strcmp(c,hold5[k]) != 0){
						hold5[++k] = c;
						//printf("%s\n",c);
						len++;
					}
				}
			}*/
		}
		j++;
	}
	i++;
    }
    return hold5;
}
