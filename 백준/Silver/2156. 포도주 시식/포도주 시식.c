#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ary[1000001] = { 0, };
int dp[1000001] = { 0, };

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
	dp[1] = ary[1], dp[2] = ary[2] + dp[1];
	for (int i = 3; i <= num; i++)
	{
		dp[i] = Max(dp[i - 1] , Max(ary[i] + ary[i - 1] + dp[i - 3], dp[i - 2] + ary[i]));
	}
	printf("%d", dp[num]);
}