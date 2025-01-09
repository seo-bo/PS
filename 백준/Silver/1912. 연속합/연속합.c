#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Max(int num1, int num2) 
{
    return num1 > num2 ? num1 : num2;
}

int main(void)
{
    int num = 0, max = 0;
    scanf("%d", &num);
    int* ary = malloc(sizeof(int) * (num+1));
    int* dp = malloc(sizeof(int) * (num+1));
    dp[0] = 0, ary[0] = 0;
    for (int i = 1; i <= num; i++)
    {
        scanf("%d", &ary[i]);
    }
    for (int i = 1; i <= num; i++)
    {
        if (i == 1)
        {
            dp[i] = ary[i];
            max = ary[i];
        }
        else 
        {
            dp[i] = Max(dp[i - 1] + ary[i], ary[i]);
            max = Max(max, dp[i]);
        }
    }
    free(ary);
    free(dp);
    printf("%d", max);
}
