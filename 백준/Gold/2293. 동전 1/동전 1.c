#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

long long coin[101] = { 0, };
long long dp[10001] = { 0, };

int main(void)
{
	dp[0] = 1;
	long long num = 0, value = 0;
	scanf("%lld %lld", &num, &value);
	for (long long i = 1; i <= num; i++)
	{
		scanf("%lld", &coin[i]);
	}
	for (long long i = 1; i <= num; i++)
	{
		for (long long j = coin[i]; j <= value; j++)
		{
			dp[j] += dp[j - coin[i]];
		}
	}
	printf("%lld", dp[value]);
}