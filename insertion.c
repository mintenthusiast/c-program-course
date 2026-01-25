#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
   /* input 1: comma-seperated numbers, sorted
    * input 2: a number that needs to be inserted into the array
    * output: a sorted array
    */

   if (argc != 3)
   {
      printf("Please input 3 arguments, in the form of: \n");
      printf("%s 1,2,3,5 4\n", argv[0]);
      return 1;
   }

   int commas = 0;
   for (int i = 0; i < strlen(argv[1]); ++i)
   {
       if (argv[1][i] == ',')
       {
          commas += 1;
       }
    }

    int *arr = (int *) malloc ((commas + 1) * 4);   
    arr[0] = atoi(&argv[1][0]);
    int j  = 1; 

    for (int i = 0; i < strlen(argv[1]); ++i)
    {
       if (argv[1][i] == ',')
       {
          arr[j] = atoi(&argv[1][i+1]);;
          j += 1;  
       }
    }

    for (int i = 0; i < commas + 1; ++i)
    {
        printf("%d\n", arr[i]);
    }

    free(arr); arr = NULL;




   return 0;
}
