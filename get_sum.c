#include<stdio.h>
#include<stdlib.h>

int get_sum(int n, int arr[])
{
    int curr_sum = 0;
    
    for (int i = 0; i < n; ++i) { curr_sum += arr[i]; }
    
    return curr_sum;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
       printf("Please enter two or more integers, like this %s 1 2 3\n", argv[0]);
       return 1;
    }
    
    int n = argc - 1;
    int *arr = (int *) malloc (4 * n);

    for (int i = 0; i < n; ++i) { arr[i] = atoi(argv[i+1]); }

    int s = get_sum(n, arr);
    printf("The sum is: %d\n", s);
    
    free(arr);
    arr = NULL;

    return 0;

}
