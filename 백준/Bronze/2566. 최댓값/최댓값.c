#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int col = 0;
	int row = 0;
	int ary[9][9] = {0,};
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	int max = ary[0][0];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (max <= ary[i][j])
			{
				max = ary[i][j];
				col = j+1;
				row = i+1;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", row, col);
}