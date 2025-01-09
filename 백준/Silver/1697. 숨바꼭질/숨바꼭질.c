#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int visited[100001] = { 0, };
int direction[2] = { -1, 1 };

typedef struct Q
{
	int front, rear, size;
	int* q;
}Q;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->size = size + 1;
	new->q = (int*)malloc(sizeof(int) * new->size);
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

void enqueue(Q* q, int num)
{
	if (full(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = num;
}

int dequeue(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	q->front = (q->front + 1) % q->size;
	return q->q[q->front];
}

void bfs(Q*q, int k)
{
	while (!empty(q))
	{
		int current = dequeue(q);
		int x = current;
		if (x == k)
		{
			printf("%d", visited[x] - 1);
			return;
		}
		for (int i = 0; i < 2; i++)
		{
			int nx = x + direction[i];
			if (nx >= 0 && nx < 100001 && !visited[nx])
			{
					int new = nx;
					enqueue(q, new);
					visited[nx] = visited[x] + 1;
			}
		}
		if (x * 2 < 100001 && !visited[x * 2])
		{
			int new = 2 * x;
			enqueue(q, new);
			visited[x * 2] = visited[x] + 1;
		}
	}
}

int main(void)
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	Q* q = create(100001);
	getchar();
	int start = n;
	enqueue(q, start);
	visited[n] = 1;
	bfs(q, k);
	free(q);
}