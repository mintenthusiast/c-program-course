#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "myarray.h"


int dot_product(int* va, int la, int* vb, int lb)
{
   int total = 0;
   int shortest_length = la < lb ? la : lb;
      
   for (int i = 0; i < shortest_length; ++i)
   {
      total += va[i] * vb[i];
   }
   
   return total;
}

int parse_vector(int *vector, char *buf)
{
   /* parse a row of data and write values into a vector array */

   int len = 0;

   char *token = strtok(buf, ",\n");
   while (token != NULL)
   {
      vector[len] = atoi(token);
      len += 1;
      token = strtok(NULL, ",\n");
   }
   return len;
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
   while (p != NULL)
   {	   
      int va[100];    
      int la = parse_vector(va, buf);

      printf("\nVector A: %d elements\n", la);
      print_array(va, la);

      p = fgets(buf, sizeof(buf), fp);

      if (p == NULL)
      { 
         printf("Odd numbered lines found. Dot product is not evaluated.");
         break;
      }

      int vb[100];
      int lb = parse_vector(vb, buf);
     
      printf("\nVector B: %d elements \n", lb);
      print_array(vb, lb);

      printf("\nThe dot product is: %d.\n", dot_product(va, la, vb, lb));

      p = fgets(buf, sizeof(buf), fp);
   }

   printf("\nfinished reading the file\n");
   
   fclose(fp);

   return 0;
}

int main(int argc, char* argv[])
{
   if (argc < 2)
   {
      printf("please input a file name.");
      return 1;
   }
   
   process_file(argv[1]);
   return 0;
}
