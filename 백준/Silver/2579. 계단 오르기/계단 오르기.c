#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[301] = { 0, };
int dp[301] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
	}
	dp[1] = ary[1]; dp[2] = dp[1] + ary[2];

	for (int i = 3; i <= num; i++)
	{
		dp[i] = ary[i] + Max(dp[i - 2] , dp[i - 3] + ary[i - 1]);
	}
	printf("%d", dp[num]);
}