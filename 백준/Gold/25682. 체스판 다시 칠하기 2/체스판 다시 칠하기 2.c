#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char chess[2001][2001] = { 0, };
int dpw[2001][2001] = { 0, };
int dpb[2001][2001] = { 0, };
int Min(int num1, int num2)
{
	return num1 < num2 ? num1 : num2;
}

int main(void)
{
	int row = 0, col = 0, size = 0;
	scanf("%d %d %d", &row, &col, &size);
	getchar();
	for (int i = 1; i <= row; i++)
	{
		scanf("%s", chess[i] + 1);
		getchar();
	}
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			if ((i + j) % 2 == 0)
			{
				dpw[i][j] = dpw[i - 1][j] + dpw[i][j - 1] - dpw[i - 1][j - 1] + (chess[i][j] == 'B');
				dpb[i][j] = dpb[i - 1][j] + dpb[i][j - 1] - dpb[i - 1][j - 1] + (chess[i][j] == 'W');
			}
			else
			{
				dpw[i][j] = dpw[i - 1][j] + dpw[i][j - 1] - dpw[i - 1][j - 1] + (chess[i][j] == 'W');
				dpb[i][j] = dpb[i - 1][j] + dpb[i][j - 1] - dpb[i - 1][j - 1] + (chess[i][j] == 'B');
			}
		}
	}
	
	int mini = size*size;

	for (int i = size; i <= row; i++)
	{
		for (int j = size; j <= col; j++)
		{
			int white = dpw[i][j] - dpw[i - size][j] - dpw[i][j - size] + dpw[i - size][j - size];
			int black = dpb[i][j] - dpb[i - size][j] - dpb[i][j - size] + dpb[i - size][j - size];
			mini = Min(mini, Min(white, black));
		}
		
	}
	printf("%d", mini);
}