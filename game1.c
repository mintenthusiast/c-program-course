#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

void print_stars(int x, int y, int row_max, int col_max, int rotate)
{
	int arrx[4];
	int arry[4];

	switch (rotate % 4)
	{
		case 0:
			arrx[0] = x; arrx[1] = x; arrx[2] = x; arrx[3] = x + 1;
			arry[0] = y; arry[1] = y + 1; arry[2] = y + 2; arry[3] = y + 2; 
			break;

		case 1:
			arrx[0] = x; arrx[1] = x + 1; arrx[2] = x + 2; arrx[3] = x;
			arry[0] = y; arry[1] = y; arry[2] = y; arry[3] = y + 1;
			break;

		case 2:
			arrx[0] = x; arrx[1] = x + 1; arrx[2] = x + 1; arrx[3] = x + 1;
			arry[0] = y; arry[1] = y; arry[2] = y + 1; arry[3] = y + 2;
			break;

		case 3:
			arrx[0] = x + 2; arrx[1] = x; arrx[2] = x + 1; arrx[3] = x + 2;
			arry[0] = y; arry[1] = y + 1; arry[2] = y + 1; arry[3] = y + 1;
			break;

		default:
			exit(0);
	}

	int counter = 0;

	for (int row = 0; row < row_max; row++)
	{
		for (int col = 0; col < col_max; col++)
		{
			if (row == arry[counter] && col == arrx[counter]) { printf(" "); counter++; }
			else { printf("*"); }
		}

		printf("\n");
	}

}

int main(int argc, char* argv[])
{
	if (argc != 5)
   	{
	   	printf("init error!");
	   	return 1;
   	}

	int row_max = atoi(argv[1]);
	int col_max = atoi(argv[2]);
	int x = atoi(argv[3]);
	int y = atoi(argv[4]);

	print_stars(x, y, row_max, col_max, 0);
	int rotate = 0;

	int w = 2;
	int h = 3;

	char input;

	while (1)
	{
		if (_kbhit())
		{
			input = _getch();

			if (input == 'w')
			{
				if (y > 0) y--;	
			}

			else if (input == 'a')
			{	
				if (x > 0) x--;
			}
	
			else if (input == 'd')
			{
				if (x < col_max - w) x++;	
			}

			else if (input = 'r')
			{
				if (x < col_max - w && y < row_max - h) rotate++; int tmp = h; h = w; w = tmp;
			}	
		}

		
		if (y < col_max - h) y++; // move down

		print_stars(x, y, row_max, col_max, rotate);
		sleep(1);

	}
	
	return 0;
}
