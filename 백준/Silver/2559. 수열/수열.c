#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, many = 0, result = 0;
	scanf("%d %d", &num, &many);
	int* ary = malloc(sizeof(int) * (num+1));
	int* prefix = malloc(sizeof(int) * (num+1));
	int* dp = malloc(sizeof(int) * (num+1));
	ary[0] = 0, prefix[0] = 0, dp[0] = 0;
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
		prefix[i] = (prefix[i - 1] + ary[i]);
	}
	
	for (int i = 1; i <= num; i++)
	{
		if (i <= many)
		{
			dp[i] = prefix[i];
		}
		else
		{
			dp[i] = Max((prefix[i] - prefix[i - many]), dp[i - 1]);
		}
	}
	printf("%d", dp[num]);
	free(ary);
	free(prefix);
	free(dp);
}
