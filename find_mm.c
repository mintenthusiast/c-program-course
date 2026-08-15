#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("init error");
		return 1;
	}

	int value;
	int curr_max = atoi(argv[1]);
	int curr_min = curr_max;

	for (int i = 2; i < argc; i++) 
	{
		value = atoi(argv[i]);
		curr_max = value > curr_max ? value : curr_max;
		curr_min = value < curr_min ? value : curr_min;

	}

	char c;
	scanf(" %c", &c);

	if (c == 'A') { printf("%d", curr_max); }
	else if (c == 'B') { printf("%d", curr_min); }
	else { printf("input error"); }

	return 0;
}
