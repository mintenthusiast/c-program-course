#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myarray.h"

int process_file (char *filename)
{
   FILE *fp = fopen(filename, "r");

   if (fp == NULL)
   {
      printf("Error: open file failed.\n");
      return 1;
   }
  
   char buf[255];


   // not hard-coded 255
   
   char *p = fgets(buf, sizeof(buf), fp);
   char *token = strtok(buf, ",\n");

   while (p != NULL)
   {
      int a[10];    
      int counter = 0;
    
      while (token != NULL)
      {
         a[counter] = atoi(token);
         counter += 1;
 
         token = strtok(NULL, ",\n");
      }
      
      p = fgets(buf, sizeof(buf), fp);
      token = strtok(buf, ",");

      // sort and print 
      sort_array(a, counter);
      print_array(a, counter);
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

   process_file(argv[1]);
   return 0;
}
