#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[2][100001] = { 0, };
int dp[2][100001] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int z = 0; z < num; z++)
	{
		int get = 0;
		scanf("%d", &get);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 1; j <= get; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		dp[0][1] = ary[0][1]; dp[1][1] = ary[1][1];
		for (int i = 2; i <= get; i++)
		{
			dp[0][i] = Max(dp[1][i - 2], dp[1][i - 1]) + ary[0][i];
			dp[1][i] = Max(dp[0][i - 2], dp[0][i - 1]) + ary[1][i];
		}
		int result = Max(dp[0][get], dp[1][get]);
		printf("%d\n", result);
	}
}