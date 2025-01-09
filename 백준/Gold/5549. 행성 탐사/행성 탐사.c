#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Joi
{
	int jungle;
	int ocean;
	int ice;
}Joi;

Joi ary[1002][1002] = { 0, };
int jsum[1002][1002] = { 0, };
int osum[1002][1002] = { 0, };
int isum[1002][1002] = { 0, };
char line[1002];

int main(void)
{
	int row = 0, col = 0,num = 0;
	scanf("%d %d %d", &row, &col ,&num);
	getchar();
	for (int i = 1; i <= row; i++)
	{
		fgets(line, sizeof(line), stdin);
		line[strcspn(line, "\n")] = 0;
		for (int j = 1; j <= col; j++)
		{
			char get = line[j - 1];
			if (get == 'J')
			{
				ary[i][j].jungle = 1;
			}
			else if (get == 'O')
			{
				ary[i][j].ocean = 1;
			}
			else if (get == 'I')
			{
				ary[i][j].ice = 1;
			}
			jsum[i][j] = ary[i][j].jungle + jsum[i - 1][j] + jsum[i][j - 1] - jsum[i - 1][j - 1];
			osum[i][j] = ary[i][j].ocean + osum[i - 1][j] + osum[i][j - 1] - osum[i - 1][j - 1];
			isum[i][j] = ary[i][j].ice + isum[i - 1][j] + isum[i][j - 1] - isum[i - 1][j - 1];
		}
	}
	
	for (int i = 0; i < num; i++)
	{
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int jresult = jsum[x2][y2] + jsum[x1 - 1][y1 - 1] - jsum[x2][y1 - 1] - jsum[x1 - 1][y2];
		int oresult = osum[x2][y2] + osum[x1 - 1][y1 - 1] - osum[x2][y1 - 1] - osum[x1 - 1][y2];
		int iresult = isum[x2][y2] + isum[x1 - 1][y1 - 1] - isum[x2][y1 - 1] - isum[x1 - 1][y2];
		printf("%d %d %d\n", jresult, oresult, iresult);
	}
}