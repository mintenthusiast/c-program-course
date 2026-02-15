#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print_file (char *filename)
{
   FILE *fp = fopen(filename, "r");

   if (fp == NULL)
   {
      printf("Error: open file failed.\n");
      return 1;
   }
  
   char buf[255];


   // not hard-cded 255
   
   char *p = fgets(buf, sizeof(buf), fp);
   char *token = strtok(buf, ",");

   while (p != NULL)
   {
      while (token != NULL)
      {
         int val = atoi(token);
         printf("%d ", val);
 
         token = strtok(NULL, ",");
      }

      p = fgets(buf, sizeof(buf), fp);
      token = strtok(buf, ",");
      printf("\n");
   }

   printf("finished reading the file\n");

   fclose(fp);
   return 0;
}

int main(int argc, char *argv[])
{
   if (argc != 2)
   {
      printf("Please input a filename!\n");
      return 1;
   }

   print_file(argv[1]);
   return 0;
}
