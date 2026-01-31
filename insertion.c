#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int insert2array(int *arr, int len, int n)
{
   /* insert n into arr[] */
   // 1) find location
   int j = 0;
   for (int i = 0; i < len; ++i)
   {
       if(arr[i] > n)
       {
          j = i;
          break;
       }
   }

   printf("j = %d, n = %d\n", j, n);
   // 2) shift arr[i], arr[i+1], ... so forth
   for (int i = len-2; i >= j; --i)
   {
      arr[i+1] = arr[i];
   }

   // 3) arr[i] = n

   arr[j] = n;

   return 0;
}


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
   int n = strlen(argv[1]);

   for (int i = 0; i < n; ++i)
   {
       if (argv[1][i] == ',')
       {
          commas += 1;
       }
    }

    int *arr = (int *) malloc ((commas + 2) * 4);   
    arr[0] = atoi(&argv[1][0]);
    int j  = 1; 

    for (int i = 0; i < n; ++i)
    {
       if (argv[1][i] == ',')
       {
          arr[j] = atoi(&argv[1][i+1]);;
          j += 1;  
       }
    }

    for (int i = 0; i < commas + 2; ++i)
    {
        printf("%d ", arr[i]);
    }

    insert2array(arr, commas + 2, atoi(argv[2]));

    for (int i = 0; i < commas + 2; ++i)
    {
        printf("%d ", arr[i]);
    }
    
    free(arr); arr = NULL;

   return 0;
}
