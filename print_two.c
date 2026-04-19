#include<stdio.h>
#include<stdlib.h>
#include "myarray.h"

int main(int argc, char* argv[])
{

   int n = argc - 1;
   int* arr = (int *) malloc (sizeof(int) * n);

   for (int i = 0; i < n; ++i) { arr[i] = atoi(argv[i+1]); }

   for (int i = 0; i < n; ++i) 
   {
      if (arr[i] % 5 == 0) { break; }
      if ((i + 1) % 2 == 0)
      {     
      printf("%d ", arr[i]); 
      }
   }

   printf("\n");

   free(arr);
   arr = NULL;

   return 0;
}
