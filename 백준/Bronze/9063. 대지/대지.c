#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x[100001];
    int y[100001];
    int num = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
        int xmax = x[0];
        int xmin = x[0];
        int ymax = y[0];
        int ymin = y[0];

   for (int i = 0; i < num; i++)
   {
       if (xmax <= x[i])
       {
           xmax = x[i];
       }
       if (xmin >= x[i])
       {
           xmin = x[i];
       }
       if (ymax <= y[i])
       {
           ymax = y[i];
       }
       if (ymin >= y[i])
       {
           ymin = y[i];
       }
   }

   int result = (xmax - xmin) * (ymax - ymin);
    
   printf("%d",result);
   return 0;
}