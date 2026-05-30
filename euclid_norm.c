#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "myarray.h"


/* 1) read all vectors from a file
 * 2) calculate the norm for each vector
 * 
 *
 *
 *
 */

double euclid_norm(int* vector, int len)
{
   double out = 0;

   for(int i = 0; i < len; i++)
   {
      out += vector[i] * vector[i];
   }

   out = sqrt(out);
   return out;
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

int process_file(char* filename)
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
      printf("\nThe norm is: %f\n", euclid_norm(va, la)); 

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
