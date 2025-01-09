#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Max 2147483647

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	int num = 0, value = 0;
	scanf("%d %d", &num, &value);
	int* cost = malloc(sizeof(int) * (num + 1));
	int* dp = malloc(sizeof(int) * (value + 1));
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &cost[i]);
	}
	for (int i = 1; i <= value; i++)
	{
		dp[i] = Max;
	}
	dp[0] = 0;
	for (int i = 1; i <= num; i++)
	{
		for (int j = cost[i]; j <= value; j++)
		{
			if (dp[j - cost[i]] != Max)
			{
				dp[j] = Min(dp[j], dp[j - cost[i]] + 1);
			}
		}
	}
	if (dp[value] == Max)
	{
		printf("%d", -1);
	}
	else
	{
		printf("%d", dp[value]);
	}
	free(cost);
	free(dp);
}