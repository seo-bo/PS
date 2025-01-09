#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[1002];
char str2[1002];
char lcs[1002];
int dp[1002][1002] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}
int main(void)
{
	scanf("%s", str1);
	getchar();
	scanf("%s", str2);
	getchar();
	int size1 = strlen(str1), size2 = strlen(str2);
	for (int i = 1; i <= size1; i++)
	{
		for (int j = 1; j <= size2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int index = dp[size1][size2];
	printf("%d\n", index);
	lcs[index] = '\0';
	while (size1 > 0 && size2 > 0)
	{
		if (str1[size1 - 1] == str2[size2 - 1])
		{
			lcs[--index] = str1[size1 - 1];
			size1--;
			size2--;
		}
		else if (dp[size1][size2 - 1] > dp[size1 - 1][size2])
		{
			size2--;
		}
		else
		{
			size1--;
		}
	}
	printf("%s", lcs);
}
