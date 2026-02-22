#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print_array(int *a, int len);

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

int sort_array(int *a, int len)
{ 
   for (int i = 0; i < len - 1; ++i)
   {
      min_loc_swap(a + i, len - i);
   }

   return 0;
}


int print_file (char *filename)
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

   print_file(argv[1]);
   return 0;
}
