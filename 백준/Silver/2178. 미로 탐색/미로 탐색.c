#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int visited[101][101] = { 0, };
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
	char list[101][101];
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
				if (g->list[nx][ny] == '1' && !visited[nx][ny])
				{
					pos new = { nx,ny };
					enqueue(q, new);
					visited[nx][ny] = visited[x][y] + 1;
				}
			}
		}
	}
}

int main(void)
{
	int n = 0, m = 0;
	scanf("%d %d", &n, &m);
	Graph* g = (Graph*)malloc(sizeof(Graph));
	Q* q = create(n * m);
	g->n = n;
	g->m = m;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", g->list[i]);
	}
	pos start = { 0,0 };
	enqueue(q, start);
	visited[0][0] = 1;
	bfs(g, q);
	printf("%d", visited[n - 1][m - 1]);
}