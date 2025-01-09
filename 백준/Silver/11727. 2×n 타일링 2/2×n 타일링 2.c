#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int dp[1001] = { 0, };

int main(void)
{
	dp[1] = 1, dp[2] = 3;
	int num = 0;
	scanf("%d", &num);
	
	for (int i = 3; i <= num; i++)
	{
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}
	printf("%d", dp[num]);
}