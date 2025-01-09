#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char ary[1002] = { 0, };
char bry[1002] = { 0, };
int dp[1002][1002] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void) 
{
	scanf("%s", ary);
	getchar();
	int size1 = strlen(ary);
	scanf("%s", bry);
	int size2 = strlen(bry);
	getchar();
	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (ary[i - 1] == bry[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d", dp[size1][size2]);
}
