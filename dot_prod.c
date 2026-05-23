#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myarray.h"


int dot_product(int* va, int la, int* vb, int lb)
{
   int total = 0;
   int shortest_length = la;

   if (la > lb)
   {
      shortest_length = lb;
   }
      
   for (int i = 0; i < shortest_length; ++i)
   {
      total += va[i] * vb[i];
   }
   
   return total;
}

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

   int va[100];    
   int la = 0;
    
   while (token != NULL)
   {
      va[la] = atoi(token);
      la += 1;
 
      token = strtok(NULL, ",\n");
   }
    
   int vb[100];
   int lb = 0;

   p = fgets(buf, sizeof(buf), fp);
   token = strtok(buf, ",");

   while (token != NULL)
   {
      vb[lb] = atoi(token);
      lb += 1;
      
      token = strtok(NULL, ",\n");
   }

   printf("finished reading the file\n");
   
   printf("Vector A: %d elements\n", la);
   print_array(va, la);

   printf("\nVector B: %d elements \n", lb);
   print_array(vb, lb);

   fclose(fp);
   return dot_product(va, la, vb, lb);
}

int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      printf("please input a file name.");
      return 1;
   }
   
   printf("\nThe dot product is: %d.", process_file(argv[1]));
   return 0;
}
