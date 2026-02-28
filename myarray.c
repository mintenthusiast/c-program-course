#include "myarray.h"
#include<stdio.h>
#include<stdlib.h>


int sort_array(int *a, int len)
{ 
   for (int i = 0; i < len - 1; ++i)
   {
      min_loc_swap(a + i, len - i);
   }

   return 0;
}

int min_loc_swap(int *a, int len)
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

   a[j] = a[0];
   a[0] = min;
  
   return 0;
}

int print_array(int *a, int len)
{
   for (int i = 0; i < len; ++i)
   {
      printf("%d ", a[i]);
   }
   printf("\n");

   return 0;
}
