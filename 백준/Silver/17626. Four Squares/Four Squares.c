#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Min(int num1, int num2)
{ 
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int* dp = (int*)malloc(sizeof(int) * (num + 1));
	dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
	for (int i = 4; i <= num; i++)
	{
		dp[i] = i;
		for (int j = 1; j <= sqrt(i); j++)
		{
			int temp = i - j * j;
			dp[i] = Min(dp[i], 1 + dp[temp]);
		}
	}
	printf("%d", dp[num]);
	free(dp);
}