#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print_space(int spaces)
{
   for(int i = 0; i < spaces; ++i)
   {
      printf(" ");
   }

   return 0;
}

int print_star(char* character, int stars)
{  
   printf("%s", character);

   for(int i = 0; i < stars - 1; ++i)
   {
      printf(" %s", character);
   }

   printf("\n");

   return 0;
}


int print_row(int row, int total_row, char* character)
{
   int stars = 2 * row + 1;
   int spaces = (strlen(character) + 1) * (total_row - row - 1);

   print_space(spaces);
   print_star(character, stars);

   return 0; 
}

int print_triangle(int total_row, char* character)
{
   for(int i = 0; i < row; ++i)
   {
      print_row(i, total_row, character);
   }
 
   return 0;
}


int main(int argc, char *argv[])
{
   if(argc != 3)
   {
      printf("Please enter the number of rows to print and a character");
      return 1;
   }

   int total_row = atoi(argv[1]);

   print_triangle(total_row, argv[2])

   return 0;
}
