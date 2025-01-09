#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int ary[3];
    int round = 0;
    int sum = 0;
 
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &ary[i]);
    }
    int max = ary[0];
    for (int i = 0; i < 3; i++)
    {
        if (max <= ary[i])
        {
            max = ary[i];
        }
        sum += ary[i];
    }
        if (sum  <= 2 * max)
        {
            round = 2 * (sum - max) - 1;
        }
        else
        {
            round = sum;
        }
        printf("%d", round);
}