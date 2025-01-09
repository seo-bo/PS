#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int visited[101][101][101] = {0,};
int direction[6][2][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

typedef struct pos
{
	int w, x, y, value;
}pos;

typedef struct Q
{
	int front, rear, size;
	pos* q;
}Q;

typedef struct Graph
{
	int n, m, w;
	int list[101][101][101];
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
		int w = space.w;
		int x = space.x;
		int y = space.y;
		int cnt = space.value;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				int nw = w + direction[i][j][0];
				int nx = x + direction[i][j][1];
				int ny = y + direction[i][j][2];
				if (nw >= 0 && nw < g->w && nx >= 0 && nx < g->n && ny >= 0 && ny < g->m)
				{
					if (g->list[nw][nx][ny] == 0 && !visited[nw][nx][ny])
					{
						visited[nw][nx][ny] = 1 + cnt;
						pos new = { nw, nx, ny, cnt + 1 };
						enqueue(q, new);
					}
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
	int w =0, m = 0, n = 0;
	scanf("%d %d %d", &m, &n, &w);
	getchar();
	g->w = w;
	g->m = m;
	g->n = n;
	Q* q = create(m * n * w);
	for (int k = 0; k < w; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &g->list[k][i][j]);
				if (g->list[k][i][j] == 1)
				{
					pos temp = { k, i, j, 1 };
					enqueue(q, temp);
					visited[k][i][j] = 1;
				}
			}
		}
	}
	bfs(g, q);
	int result = 0;
	for (int k = 0; k < w; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g->list[k][i][j] == 0 && visited[k][i][j] == 0)
				{
					printf("-1");
					return 0;
				}
				result = Max(result, visited[k][i][j]);
			}
		}
	}
	printf("%d", result - 1);
}
