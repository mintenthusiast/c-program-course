#include <stdio.h>
#include <stdlib.h>

void print_stars(int x, int y, int row_max, int col_max)
{
	int arrx[4] = {x, x, x, x + 1};
	int arry[4] = {y, y + 1, y + 2, y + 2};

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

	print_stars(x, y, row_max, col_max);
	char input;

	while (1)
	{
		scanf(" %c", &input);

		if (input == 'w')
		{
			if (y > 0) y--;	
		}

		else if (input == 's')
		{
			if (y < row_max - 3) y++;
		}

		else if (input == 'a')
		{	
			if (x > 0) x--;
		}
	
		else if (input == 'd')
		{
			if (x < col_max - 2) x++;	
		}

		else { exit(0); }

		print_stars(x, y, row_max, col_max);

	}
	
	return 0;
}
