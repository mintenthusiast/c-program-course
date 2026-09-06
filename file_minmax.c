#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find_max(int *arr, int len)
{
	int curr_max = arr[0];

	for (int i = 1; i < len; i++)
	{
		curr_max = arr[i] > curr_max ? arr[i] : curr_max;
	}

	return curr_max;
}

int find_min(int *arr, int len)
{
	int curr_min = arr[0];

	for (int i = 1; i < len; i ++)
	{
		curr_min = arr[i] < curr_min ? arr[i] : curr_min;
	}

	return curr_min;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("INIT ERROR");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("FILEOPEN ERROR");
		return 1;
	}

	char buf[255];
	char *p = fgets(buf, sizeof(buf), fp);

	while (p != NULL)
	{
		int arr[10];
		int len = 0;

		char *token = strtok(buf, ",");

		while (token != NULL)
		{
			arr[len] = atoi(token);
			len++;
			token = strtok(NULL, ",");
		}

		printf("MAX: %d MIN: %d\n", find_max(arr, len), find_min(arr, len));
		p = fgets(buf, sizeof(buf), fp);
	}

	fclose(fp);
	return 0;
}

