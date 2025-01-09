#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int dp[10001] = { 0, };
int ary[10001] = { 0, };

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
	
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = Max(dp[i], dp[i - j] + ary[j]);
		}
	}
	printf("%d", dp[num]);
}