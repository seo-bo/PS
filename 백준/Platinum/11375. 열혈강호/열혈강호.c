#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int N = 0, M =0;
int ary[1001][1001] = {0,};
int match[1001] = { 0, };
int visited[1001] = { 0, };

int dfs(int num)
{
	if (visited[num])
	{
		return 0;
	}
	visited[num] = 1;
	for (int i = 1; i <= M; i++)
	{
		if (ary[num][i])
		{
			if (!match[i] || dfs(match[i]))
			{
				match[i] = num;
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	int count = 0;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		for (int j = 0; j < temp; j++)
		{
			int work = 0;
			scanf("%d", &work);
			ary[i][work] = 1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
		{
			count++;
		}
	}
	printf("%d", count);
}