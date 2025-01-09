#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char ary[103][103][103] = { 0, };
int main(void)
{
	int num1 = 0, num2 = 0, num3 = 0;
	scanf("%d %d %d", &num2, &num3, &num1); // num1은 층, num2는 행, num3은 열
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			scanf("%s", ary[i][j] + 1);
			getchar();
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			for (int k = 1; k <= num3; k++)
			{
				int sum = 0;
				if (ary[i][j][k] == '.')
				{
					sum += (ary[i - 1][j - 1][k - 1] == '*') + (ary[i - 1][j - 1][k] == '*') + (ary[i - 1][j - 1][k + 1] == '*') + (ary[i - 1][j][k - 1] == '*') + (ary[i - 1][j][k] == '*') + (ary[i - 1][j][k + 1] == '*') + (ary[i - 1][j + 1][k - 1] == '*') + (ary[i - 1][j + 1][k] == '*') + (ary[i - 1][j + 1][k + 1] == '*');
					sum += (ary[i][j - 1][k - 1] == '*') + (ary[i][j - 1][k] == '*') + (ary[i][j - 1][k + 1] == '*') + (ary[i][j][k - 1] == '*') + (ary[i][j][k + 1] == '*') + (ary[i][j + 1][k - 1] == '*') + (ary[i][j + 1][k] == '*') + (ary[i][j + 1][k + 1] == '*');
					sum += (ary[i + 1][j - 1][k - 1] == '*') + (ary[i + 1][j - 1][k] == '*') + (ary[i + 1][j - 1][k + 1] == '*') + (ary[i + 1][j][k - 1] == '*') + (ary[i + 1][j][k] == '*') + (ary[i + 1][j][k + 1] == '*') + (ary[i + 1][j + 1][k - 1] == '*') + (ary[i + 1][j + 1][k] == '*') + (ary[i + 1][j + 1][k + 1] == '*');
					ary[i][j][k] = (sum % 10) + '0';
				}
			}
		}
	}
	for (int i = 1; i <= num1; i++)
	{
		for (int j = 1; j <= num2; j++)
		{
			printf("%s\n", ary[i][j] + 1);
		}
	}
}