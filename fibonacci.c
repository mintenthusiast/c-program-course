#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n)
{   
    if (n == 0) { return 0; }

    int memory_size = (n + 1) * 4;
    int *arr = (int *) malloc (memory_size); 

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    int out = arr[n];
    free(arr);
    arr = NULL;

    return out;
}


int main(int argc, char *argv[])
{   
    while (1)
    {
        printf("Which Fibonacci number do you want to know?\n");
        printf("Please input ->: ");    

        int n;
        scanf(" %d", &n);
    
        printf("Your input is: %d\n", n);
    
        if (n < 0)
        {
            printf("Please input a positive integer.\n");
            return 1;
        }

        int number = fibonacci(n); 
        printf("The number is: %d\n", number);    
 
        printf("Do you want to continue? y/n\n");
   
        char c;
        scanf(" %c", &c);

        if (c == 'y') { printf("You want to continue. \n"); }
        else if(c == 'n') { printf("Goodbye.\n"); break; }
        else { printf("Sorry, I don't understand your input, goodbye. \n"); break;}
    }

    return 0;
}
