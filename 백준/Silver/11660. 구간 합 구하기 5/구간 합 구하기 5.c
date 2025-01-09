#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int num = 0, test = 0;
	scanf("%d %d", &num, &test);
	getchar();
	num++;
	int** prefix = (int**)malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++)
	{
		prefix[i] = (int*)malloc(sizeof(int) * num);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i == 0 || j == 0)
			{
				prefix[i][j] = 0;
			}
			else
			{
				int temp = 0;
				scanf("%d", &temp);
				getchar();
				prefix[i][j] = temp + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
			}
		}
	}
	for (int i = 0; i < test; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		getchar();
		int result = prefix[x2][y2] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2] + prefix[x1 - 1][y1 - 1];
		printf("%d\n", result);
	}
	for (int i = 0; i < num; i++)
	{
		free(prefix[i]);
	}
	free(prefix);
}