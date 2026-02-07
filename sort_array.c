#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min_loc(int *a, int len)
{
   int j = 0;
   int min = a[0];

   for (int i = 0; i < len; ++i)
   {
      if(min > a[i])
      {
         min = a[i];
         j = i;
      }
   }

   printf("The min value is: %d, the index of the min is: %d\n", min, j);
   
   return 0;
}

int main(int argc, char *argv[])
{
   if (argc != 3) 
   {
      printf("Please input a comma-seperated array and a number!\n");
      return 1;
   }

   int n = strlen(argv[1]);
   int commas = 0;
   for (int i = 0; i < n; ++i)
   {
      if (argv[1][i] == ',')
      {
         commas += 1;
      }
   }

   int length = commas + 1;
   int *arr = (int *) malloc((length + 1) * sizeof(int));
   
   arr[0] = atoi(&argv[1][0]);
   int j = 1;
   
   for (int i = 0; i < n; ++i)
   {
      if(argv[1][i] == ',')
      {
         arr[j] = atoi(&argv[1][i+1]);
         j += 1;
      }
   } 

   min_loc(arr, length);

   free(arr);
   arr = NULL;

   return 0;

}
