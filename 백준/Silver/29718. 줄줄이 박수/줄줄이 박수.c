#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ary[2001][2001] = { 0, };
int sum[2001] = { 0, };
int result[2001] = { 0, };

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int row = 0, col = 0, max =0;
	scanf("%d %d", &row, &col);
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			scanf("%d", &ary[i][j]);
			sum[j] += ary[i][j];
		}
	}
	result[1] = sum[1];
	for (int i = 1; i <= col; i++)
	{	
		result[i] = result[i - 1] + sum[i];
	}
	int cont = 0;
	scanf("%d", &cont);
	for (int i = cont; i <= col; i++)
	{
		max = Max(max, result[i] - result[i - cont]);
	}
	printf("%d", max);
}