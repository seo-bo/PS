#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[1000001] = { 0, };

int Min(int num1, int num2)
{
	return (num1 < num2) ? num1 : num2;
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	dp[1] = 0; dp[2] = 1; dp[3] = 1;
	for (int i = 4; i <= num; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 3 == 0)
		{
			dp[i] = Min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0)
		{
			dp[i] = Min(dp[i], dp[i / 2] + 1);
		}
	}
	printf("%d", dp[num]);
}