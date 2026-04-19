#include<stdio.h>
#include<stdlib.h>
#include "myarray.h"

int main(int argc, char* argv[])
{

   int n = argc - 1;
   int* arr = (int *) malloc (sizeof(int) * n);
   int* three_arr = (int *) malloc (sizeof(int) * (n / 3));

   for (int i = 0; i < n; ++i) { arr[i] = atoi(argv[i+1]); }

   for (int i = 0; i < n; ++i) 
   {
      if ((i + 1) % 3 == 0)
      {
      printf("%d ", arr[i]); 
      three_arr[i / 3] = arr[i] * 3;
      }
   }

   printf("\n");
   print_array(three_arr, n / 3);

   free(arr);
   free(three_arr);

   arr = NULL;
   three_arr = NULL;

   return 0;
}
