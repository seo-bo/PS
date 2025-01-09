#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int visited[1001][1001] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

typedef struct pos
{
	int x, y, value;
}pos;

typedef struct Q
{
	int front, rear, size;
	pos* q;
}Q;

typedef struct Graph
{
	int n, m;
	int list[1001][1001];
}Graph;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = new->rear = 0;
	new->size = size + 1;
	new->q = (pos*)malloc(sizeof(pos) * new->size);
	return new;
}

int empty(Q* q)
{
	return q->front == q->rear;
}

void enqueue(Q* q, pos num)
{
	q->front = (q->front + 1) % q->size;
	q->q[q->front] = num;
}

pos dequeue(Q* q)
{
	q->rear = (q->rear + 1) % q->size;
	return q->q[q->rear];
}

void bfs(Graph* g, Q* q)
{
	while (!empty(q))
	{
		pos space = dequeue(q);
		int x = space.x;
		int y = space.y;
		int cnt = space.value;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < g->n && ny >= 0 && ny < g->m)
			{
				if (g->list[nx][ny] == 0 && !visited[nx][ny])
				{
					visited[nx][ny] = 1 + cnt;
					pos new = { nx, ny, cnt + 1 };
					enqueue(q, new);
				}
			}
		}
	}
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	Graph* g = (Graph*)malloc(sizeof(Graph));
	memset(g->list, 0, sizeof(g->list));
	int m = 0, n = 0;
	scanf("%d %d", &m, &n);
	getchar();
	g->m = m;
	g->n = n;
	Q* q = create(m * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &g->list[i][j]);
			if (g->list[i][j] == 1)
			{
				pos temp = { i, j, 1 };
				enqueue(q, temp);
				visited[i][j] = 1;
			}
		}
	}
	bfs(g, q);
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (g->list[i][j] == 0 && visited[i][j] == 0)
			{
				printf("-1");
				return 0;
			}
			result = Max(result, visited[i][j]);
		}
	}
	printf("%d", result - 1);
}
