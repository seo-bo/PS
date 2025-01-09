#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visited[501][501] = {0,};
int draw[501 * 501] = { 0, };
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int size = 0;

typedef struct Graph
{
	int n, m;
	int list[501][501];
}Graph;

void init(Graph* g, int x, int y)
{
	g->n = x;
	g->m = y;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			scanf("%d", &g->list[i][j]);
			getchar();
		}
			
	}
}

void dfs(Graph* g, int x, int y)
{
	visited[x][y] = 1;
	draw[size]++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && ny >= 0 && nx < g->n && ny < g->m)
		{
			if (g->list[nx][ny] && !visited[nx][ny])
			{
				dfs(g, nx, ny);
			}
		}
	}
}

int compare(const void* num1, const void* num2)
{
	return *(int*)num2 - *(int*)num1;
}

int main(void)
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	int num = 0, num2 = 0;
	scanf("%d %d", &num, &num2);
	init(g, num, num2);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			if (g->list[i][j] && !visited[i][j])
			{
				dfs(g, i, j);
				size++;
			}
		}
	}
	printf("%d\n", size);
	qsort(draw, size, sizeof(int), compare);
	printf("%d\n", draw[0]);
	free(g);
}