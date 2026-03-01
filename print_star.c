#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print_triangle(int row, int total_row, char* character)
{
   int stars = 2 * row + 1;
   int spaces = (strlen(character) + 1) * (total_row - row - 1);

   for(int i = 0; i < spaces; ++i)
   {
      printf(" ");
   }
   
   printf("%s", character);

   for(int i = 0; i < stars - 1; ++i)
   {
      printf(" %s", character);
   }

   printf("\n");

   return 0; 
}


int main(int argc, char *argv[])
{
   if(argc != 3)
   {
      printf("Please enter the number of rows to print and a character");
      return 1;
   }

   int row = atoi(argv[1]);

   for(int i = 0; i < row; ++i)
   {
      print_triangle(i, row, argv[2]);
   }

   return 0;
}
