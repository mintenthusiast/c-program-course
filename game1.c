#include <stdio.h>
#include <stdlib.h>

void print_stars(int x, int y, int row_max, int col_max)
{
	for (int row = 0; row < row_max; row++)

	{
		for (int col = 0; col < col_max; col++)
		{
			if (row == x && col == y) { printf(" "); }
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
			if (x > 0) x--;	
		}

		else if (input == 's')
		{
			if (x < row_max - 1) x++;
		}

		else if (input == 'a')
		{	
			if (y > 0) y--;
		}
	
		else if (input == 'd')
		{
			if (y < col_max - 1) y++;	
		}

		else { exit(0); }

		print_stars(x, y, row_max, col_max);

	}
	
	return 0;
}
