#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n, int *arr)
{   
    if (n == 0) { return 0; }

    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        printf("Computed: f(%d) =  %d\n", i, arr[i]);
    }

    return arr[n];
}


int main(int argc, char *argv[])
{   
    int max = 46;
    int memory_size = max * 4;
    int *arr = (int *) malloc(memory_size);

    int max_computed = 0;

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
        
        if (n > max) 
        {
            printf("Please input an integer that is <= %d. \n", max);
            return 1;
        }
       
        int number  = 0;
 
        if (n > max_computed)
        {
            max_computed = n;
            number = fibonacci(n, arr);
        }
        else
        {
            number = arr[n];
        }
 
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
