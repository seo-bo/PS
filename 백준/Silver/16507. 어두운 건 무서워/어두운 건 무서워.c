#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[1001][1001] = { 0, };
int sum[1001][1001] = { 0, };

int main(void)
{
	int row = 0, col = 0, num =0;
	scanf("%d %d %d", &row, &col, &num);
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			scanf("%d", &ary[i][j]);
			sum[i][j] = ary[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	for (int i = 0; i < num; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x2][y1 - 1] - sum[x1 - 1][y2];
		printf("%d\n", result / ((x2 - x1 + 1) * (y2 - y1 + 1)));
	}
}