#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long int ary[2000005] = { 0, };

long long int ary1[2000005] = { 0, };

int compare(const void* num1, const void* num2)
{
   long long int a = *(long long int*)num1;
   long long int b = *(long long int*)num2;
   if (a > b)
   {
      return 1;
   }
   else if (a < b)
   {
      return -1;
   }
   else
   {
      return 0;
   }
}

int main(void)
{
   int num1 = 0;
   long long int num2 = 0;

   scanf("%d %lld", &num1, &num2);
   long long int num3 = (num2 + 1) * num2 / 2;
   for (int i = 0; i < num1; i++)
   {
      scanf("%lld", &ary[i]);
   }
   qsort(ary, num1, sizeof(long long int), compare);

   int index = 0;
   for (int i = 0; i < num1; i++)
   {
      if (ary[i] != ary[i + 1])
      {
         ary1[index] = ary[i];
         index++;
      }
   }
   for (int i = 0; i < index; i++)
   {
      if (ary1[i] <= num2)
      {
         num3 -= ary1[i];
      }
   }
   printf("%lld", num3);
}

