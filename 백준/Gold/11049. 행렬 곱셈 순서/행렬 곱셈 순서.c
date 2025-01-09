#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 2147483647

long long ary[501][2] = { 0, };
long long dp[501][501] = { 0, };

long long Min(long long num1, long long num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%lld %lld", &ary[i][0], &ary[i][1]);
	}
	for (int i = 1; i < num; i++)
	{
		for (int j = 1; i + j <= num; j++)
		{
			dp[j][i + j] = 2147483647;
			for (int k = j; k <= i + j; k++)
			{
				dp[j][i + j] = Min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (ary[j][0] * ary[k][1] * ary[i + j][1]));
			}
		}
	}
	printf("%lld", dp[1][num]);
}