#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[502][502] = {0,};
int dp[502][502] = {0,};

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, result = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &ary[i][j]);
			getchar();
		}
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = Max(dp[i - 1][j], dp[i - 1][j - 1]) + ary[i][j];
			result = Max(result, dp[i][j]);
		}
	}
	printf("%d", result);
}
