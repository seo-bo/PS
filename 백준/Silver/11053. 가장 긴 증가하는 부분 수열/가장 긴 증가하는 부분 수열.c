#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1001] = { 0, };
int dp[1001] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void) 
{
	int num = 0, result =0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 1; i <= num; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (ary[j] < ary[i])
			{
				dp[i] = Max(dp[i], dp[j] + 1);
			}
		}
		result = Max(result, dp[i]);
	}
	printf("%d", result);
}
