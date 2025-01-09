#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cost[1001][3] = { 0, };
int dp[1001][3] = { 0, };

int Min(int num1, int num2)
{
    return (num1 > num2) ? num2 : num1;
}

int main(void)
{
    int num = 0, result =0;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++)
    {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }
    dp[1][0] = cost[1][0];
    dp[1][1] = cost[1][1];
    dp[1][2] = cost[1][2];

    for (int i = 2; i <= num; i++)
    {
        dp[i][0] = Min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = Min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = Min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }
    result = Min(Min(dp[num][0], dp[num][1]), dp[num][2]);
    printf("%d", result);
}
