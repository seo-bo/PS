#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int dp[10001] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, byte = 0;
	scanf("%d %d", &num, &byte);
	int** ary = (int**)malloc(sizeof(int*) * (num + 1));
	for (int i = 0; i <= num; i++)
	{
		ary[i] = malloc(sizeof(int) * 2);
		if (i > 0)
		{
			scanf("%d", &ary[i][0]);
		}
	}
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i][1]);
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 10000; j >= ary[i][1]; j--)
		{
			dp[j] = Max(dp[j], dp[j - ary[i][1]] + ary[i][0]);
		}
	}
	for (int i = 0; i <= 10000; i++)
	{
		if (dp[i] >= byte)
		{
			printf("%d", i);
			for (int i = 0; i <= num; i++)
			{
				free(ary[i]);
			}
			free(ary);
			return 0;
		}
	}
}