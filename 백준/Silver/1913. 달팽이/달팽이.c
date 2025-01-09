#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int low[4] = { -1,0,1,0 };
	int col[4] = { 0,1,0,-1 };
	int derection = 0, count = 1, num = 0, turn = 0, fill = 2, rex =0, rey = 0, result = 0;
	scanf("%d", &num);
	scanf("%d", &result);
	int cen = num / 2;
	int curx = cen, cury = cen;
	int** ary = (int**)malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++)
	{
		ary[i] = (int*)malloc(sizeof(int) * num);
	}
	ary[cen][cen] = 1;
	for (int i = 0; i < 2 * num - 4; i++)
	{
		if (turn != 0 && turn % 2 == 0)
		{
			count++;
		}
		for (int j = 0; j < count; j++)
		{
			ary[curx + low[derection]][cury + col[derection]] = fill;
			curx = curx + low[derection];
			cury = cury + col[derection];
			fill++;
		}
		derection = (derection + 1) % 4;
		turn++;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < num-1; j++)
		{
			ary[curx + low[derection]][cury + col[derection]] = fill;
			curx = curx + low[derection];
			cury = cury + col[derection];
			fill++;
		}
		derection = (derection + 1) % 4;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%d ", ary[i][j]);
			if (ary[i][j] == result)
			{
				rex = i + 1;
				rey = j + 1;
			}
		}
		printf("\n");
	}
	printf("%d %d", rex, rey);
	for (int i = 0; i < num; i++)
	{
		free(ary[i]);
	}
	free(ary);
	
}

