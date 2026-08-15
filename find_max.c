#include<stdio.h>
#include<stdlib.h>

void find_max(int len, char* nums[])
{
	int curr_max = atoi(nums[0]);

	for (int i = 0; i < len; i++)
	{
		if (atoi(nums[i]) > curr_max) { curr_max = atoi(nums[i]); }
	}
	
	printf("%d", curr_max);
}
		
int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		printf("init error! Please input >= 3 integer arguments for comparison!");
		return 1;
	}

	find_max(argc - 1, &argv[1]);
	return 0;
}


