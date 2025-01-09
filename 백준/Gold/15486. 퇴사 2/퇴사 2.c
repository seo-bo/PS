#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int* dp = (int*)malloc(sizeof(int) * (num + 1));
	int** ary = (int**)malloc(sizeof(int*) * (num + 1));
	dp[0] = 0;
	for (int i = 1; i <= num; i++)
	{
		ary[i] = malloc(sizeof(int) * 2);
		scanf("%d %d", &ary[i][0], &ary[i][1]);
		dp[i] = 0;
	}
	for (int i = 1; i <= num; i++)
	{
		dp[i] = Max(dp[i], dp[i - 1]);
		if (i + ary[i][0] - 1 <= num)
		{
			dp[i + ary[i][0] - 1] = Max(dp[i + ary[i][0] - 1], dp[i - 1] + ary[i][1]);
		}
	}
	printf("%d", dp[num]);
}