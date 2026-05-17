#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myarray.h"

void process_file (char *filename)
{
   FILE *fp = fopen(filename, "r");
   int dot_product = 0;

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
}

int dot_product(int* va, int la, int* vb, int lb)
{
   int dot_product = 0;

   if (la != lb)
   {
      printf("Vector element numbers are not equal.");
      return 67;
   }

   for (int i = 0; i < la; ++i)
   {
      dot_product += va[i] * vb[i];
   }
   
   return dot_product;
}

int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      print("please input a file name.");
      return 1;
   }
   
   process_file(argv[1]);
   return 0;
}
