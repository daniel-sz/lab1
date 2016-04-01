#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	srand(argc==3?atoi(argv[2]):time(NULL));
	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	char **square = new char*[n];
	
	for (int i = 0; i < n; ++i)
	{
		square[i] = new char [n];
	}
	for (int i = 0; i < (n*n); ++i)
	{
		int x=i/n, y=i%n;
		square[x][y]='a'+rand()%('z'-'a');
	}
	return square;
}

void drawCharSquare(char **square, int n)
{
	char z;
	for (int i = 0; i < (n*n); ++i)
	{
		int x=i/n, y=i%n;
		(i%n)==(n-1)?z=13:z=' ';
		printf("%c%c",square[x][y],y==n-1?10:32);  //Na windowsie to nie zadziała, bo: https://goo.gl/VpES74 ale wtedy można zamiast %c użyć %s i wstawić "\n"
	}
	for(int i=0;i<n;i++) delete [] square[i];
	delete [] square;
}
