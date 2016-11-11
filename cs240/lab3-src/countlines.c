
#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char ** argv) {
	int c;
	int lines=0;
	c=argc;
	char * fileName = argv[1];
	FILE * fd = fopen(fileName, "r");
	if (fd == NULL)
	{
		printf("Could not open file %s\n", fileName);
		exit(1);
	}
	//while ((c=getChar()) != EOF)
	while ((c=fgetc(fd)) != EOF)
	{
		if (c=='\n')
			lines++;
	}
	printf("Program that counts lines.\n");
	printf("Total lines: %d\n", lines);
	exit(0);
}
