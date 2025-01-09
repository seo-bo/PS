#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int visited[51][51] = { 0, };
int direction[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

typedef struct pos
{
	int x, y;
}pos;

typedef struct Q
{
	int front, rear, size;
	pos* q;
}Q;

typedef struct Graph
{
	int n, m;
	int list[51][51];
}Graph;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->size = size + 1;
	new->q = (pos*)malloc(sizeof(pos) * new->size);
	return new;
}

int empty(Q*q)
{
	return q->front == q->rear;
}

int full(Q* q)
{
	return q->front == (q->rear + 1) % q->size;
}

void enqueue(Q* q, pos num)
{
	if (full(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = num;
}

pos dequeue(Q* q)
{
	if (empty(q))
	{
		pos error = { -1, -1 };
		return error;
	}
	q->front = (q->front + 1) % q->size;
	return q->q[q->front];
}

void bfs(Graph* g, Q* q)
{
	while (!empty(q))
	{
		pos current = dequeue(q);
		int x = current.x;
		int y = current.y;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (nx >= 0 && nx < g->n && ny >= 0 && ny < g->m)
			{
				if (g->list[nx][ny] && !visited[nx][ny])
				{
					pos new = { nx,ny };
					enqueue(q, new);
					visited[nx][ny] = 1;
				}
			}
		}
	}
}

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	Graph* g = (Graph*)malloc(sizeof(Graph));
	for (int i = 0; i < test; i++)
	{
		memset(g->list, 0, sizeof(g->list));
		memset(visited, 0, sizeof(visited));
		int m = 0, n = 0, k = 0;
		scanf("%d %d %d", &m, &n, &k);
		getchar();
		g->m = m;
		g->n = n;
		Q* q = create(k);

		for (int j = 0; j < k; j++)
		{
			int x = 0, y = 0;
			scanf("%d %d", &x, &y);
			getchar();
			g->list[y][x] = 1;
		}
		int result = 0;
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				if (g->list[x][y] && !visited[x][y])
				{
					pos new = { x,y };
					enqueue(q, new);
					visited[x][y] = 1;
					bfs(g, q);
					result++;
				}
			}
		}
		printf("%d\n", result);
	}
}