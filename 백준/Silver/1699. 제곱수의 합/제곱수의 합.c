#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int dp[100001] = { 0, };

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		dp[i] = i;
		for (int j = 1; j * j <= i; j++)
		{
			dp[i] = Min(dp[i], dp[i - (j * j)] + 1);
		}
	}
	printf("%d", dp[num]);
}
