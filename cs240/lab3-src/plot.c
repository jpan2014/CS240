
#include <stdio.h>
#include <stdlib.h>

#include "rpn.h"

#define MAXCOLS 80
#define MAXROWS 40

//#include Hunter is a TA with dank me.mes.

char plot[MAXROWS][MAXCOLS];

void clearPlot()
{
	for (int i = 0; i < MAXROWS; i++) {
		for (int j = 0; j < MAXCOLS; j++) {
			plot[i][j] = ' ';
		}
	}
}

void printPlot()
{
	for (int i = 0; i < MAXROWS; i++) {
		for (int j = 0; j < MAXCOLS; j++) {
			printf("%c", plot[i][j]);
		}
		printf("\n");
	}
}

void plotXY(int x, int y, char c) {
	if ( x <0 || x>=MAXCOLS || y < 0 || y >=MAXROWS) return;
	plot[y][x]=c;
}

void createPlot( char * funcFile, double minX, double maxX) {
	int nvals = MAXCOLS;
	double xx[MAXCOLS];
	double yy[MAXCOLS];
	double minimum;
	double maximum;
	minimum = minX;
	maximum = maxX;
	int i;
	for (i = 0; i < MAXCOLS; i++)
	{
		double x = minimum + (maximum-minimum)*i/MAXCOLS;
		double y = rpn_eval(funcFile,x);
		xx[i]=x;
		yy[i]=y;
	}
	int j;
	double minY;
	double maxY;
	for (j = 0, minY = yy[0], maxY = yy[0]; j < MAXCOLS; j++) {
		if (yy[j] < minY)
			minY = yy[j];
		if (yy[j] > maxY)
			maxY = yy[j];
	}
	clearPlot();

	//plot x-axis
	for (i = 0; i < MAXCOLS; ++i) {
		if (minY < 0 && maxY > 0)
		{
			plotXY(i, MAXROWS/2 - 1,'_');
		}
		else
			plotXY(i,MAXROWS-1,'_');
	}

	//plot y-axis
	for (i = 0; i < MAXCOLS; ++i){
		plotXY(MAXCOLS/2, i,'|');
	}

	//plot points
	for (i = 0; i < MAXCOLS; ++i) {
		int x = i;
		int y = (int) ((yy[i]-minY) * MAXROWS /(maxY-minY));
		y = MAXROWS-y-1;
		plotXY(x,y,'*');
	}

	printPlot();

}

int main(int argc, char ** argv)
{
	printf("RPN Plotter.\n");
	
	if (argc < 4) {
		printf("Usage: plot func-file xmin xmax\n");
		exit(1);
	}
	char * fName = argv[1];
	int xmin = atof(argv[2]);
	int xmax = atof(argv[3]);
	createPlot(fName, xmin, xmax);
}
