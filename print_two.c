#include<stdio.h>
#include<stdlib.h>
#include "myarray.h"

int main(int argc, char* argv[])
{

   int n = argc - 1;
   int* arr = (int *) malloc (sizeof(int) * n);

   for (int i = 0; i < n; ++i) { if (atoi(argv[i+1]) % 5 == 0) { return 1; } arr[i] = atoi(argv[i+1]); }

   for (int i = 0; i < n; ++i) 
   {
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
