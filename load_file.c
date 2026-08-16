#include <stdio.h>
#include <stdlib.h>
#include "myarray.h"

int process_file (char *filename)
{
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Error: File Not Found. \n");
		return 1;
	}

	char buf[255];

	char *p = fgets(buf, sizeof(buf), fp);

	while (p != NULL)
	{
		printf("%s", buf);	
		p = fgets(buf, sizeof(buf), fp);
	}


	fclose(fp);
	return 0;
}



int main (int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Please input a valid filename.");
		return 1;
	}

	process_file(argv[1]);
	return 0;
}
