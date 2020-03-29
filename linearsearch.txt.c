//3.Write a C program for linear search algorithm.
#include <stdio.h>
long linearsearch(long [], long, long);
int main()
{
   long a[100], search, i, n, position;
   printf("Input number of elements in array\n");
   scanf("%ld",&n);
   printf("Input %d numbers\n",n);
   for (i = 0; i < n; i++)
   {
      scanf("%ld", &a[i]);
   }
   printf("Input a number to search\n");
   scanf("%ld", &search);
   position = linearsearch(a,n,search);
   if (position == -1)
      printf("%d is not present in the array.\n",search);
   else
      printf("%d is present at location %d.\n",search,position+1);
   return 0;
}
long linearsearch(long a[], long n, long find)
{
   long i;

   for (i = 0 ;i < n ; i++ )
   {
      if (a[i] == find)
         return i;
   }

   return -1;
}
