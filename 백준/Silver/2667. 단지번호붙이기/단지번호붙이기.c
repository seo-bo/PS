#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int visited[26][26] = {0,};
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int apart[26 * 26] = { 0, };
int temp = 0;

typedef struct Graph
{
	int n;
	char list[26][26];
}Graph;

void init(Graph* g, int size)
{
	g->n = size;
	for (int i = 0; i <size; i++)
	{
			scanf("%s", &g->list[i]);
			getchar();
	}
}

void dfs(Graph* g, int x, int y)
{
	visited[x][y] = 1;
	apart[temp]++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (nx >= 0 && ny >= 0 && nx < g->n && ny < g->n)
		{
			if (g->list[nx][ny] == '1' && !visited[nx][ny])
			{
				dfs(g, nx, ny);
			}
		}
	}
}

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	int num = 0;
	scanf("%d", &num);
	init(g, num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (g->list[i][j] == '1' && !visited[i][j])
			{
				dfs(g, i, j);
				temp++;
			}
		}
	}
	printf("%d\n", temp);
	qsort(apart, temp, sizeof(int), compare);
	for (int i = 0; i < temp; i++)
	{
		printf("%d\n", apart[i]);
	}
	free(g);
}