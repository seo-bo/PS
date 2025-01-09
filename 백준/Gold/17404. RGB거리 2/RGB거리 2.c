#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cost[1001][3] = { 0, };
int dp[1001][3] = { 0, };
int result = 1000001; 

int Min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

int main(void)
{
    int num = 0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    for (int k = 0; k < 3; k++) 
    { 
        for (int i = 0; i < 3; i++) 
        {
            if (i == k)
            {
                dp[1][i] = cost[1][i];
            }  
            else 
            { 
                dp[1][i] = 1000001;
            }
        }
        for (int i = 2; i <= num; i++)
        {
            dp[i][0] = Min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = Min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = Min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }
        for (int i = 0; i < 3; i++) 
        {
            if (i == k)
            {
                continue;
            }
            result = Min(result, dp[num][i]); 
        }
    }
    printf("%d", result);
}
