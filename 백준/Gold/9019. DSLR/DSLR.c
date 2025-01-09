#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int start = 0, end = 0, head = -1;
int visited[10001] = { 0, }, from[10001] = { 0, };
char command[10001], path[10001];

typedef struct Q
{
	int front, rear, size;
	int* q;
}Q;

Q* create()
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = new->rear = 0;
	new->size = 10002;
	new->q = (int*)malloc(sizeof(int) * new->size);
	return new;
}

int empty(Q* q)
{
	return q->front == q->rear;
}

void enqueue(Q* q, int num)
{
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = num;
}

int dequeue(Q* q)
{
	q->front = (q->front + 1) % q->size;
	return q->q[q->front];
}

int command_D(int num)
{
	return (2 * num) % 10000;
}

int command_S(int num)
{
	return (num == 0) ? 9999 : (num - 1);
}

int command_L(int num)
{
	return (num % 1000) * 10 + num / 1000;
}

int command_R(int num)
{
	return (num % 10) * 1000 + num / 10;
}

void bfs()
{
	Q* q = create();
	visited[start] = 1;
	enqueue(q, start);
	while (!empty(q))
	{
		int temp = dequeue(q);
		int idx = 0;
		if (temp == end)
		{
			int idx = 0;
			while (temp != start)
			{
				path[idx++] = command[temp];
				temp = from[temp];
			}
			while (idx--)
			{
				printf("%c", path[idx]);
			}
			printf("\n");
			free(q->q);
			free(q);
			return;
		}
		int next = command_D(temp);
		if (!visited[next])
		{
			visited[next] = 1;
			enqueue(q, next);
			command[next] = 'D';
			from[next] = temp;
		}

		next = command_S(temp);
		if (!visited[next])
		{
			visited[next] = 1;
			enqueue(q, next);
			command[next] = 'S';
			from[next] = temp;
		}

		next = command_L(temp);
		if (!visited[next])
		{
			visited[next] = 1;
			enqueue(q, next);
			command[next] = 'L';
			from[next] = temp;
		}

		next = command_R(temp);
		if (!visited[next])
		{
			visited[next] = 1;
			enqueue(q, next);
			command[next] = 'R';
			from[next] = temp;
		}
	}
	free(q->q);
	free(q);
}

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	getchar();
	for (int i = 0; i < test; i++)
	{
		memset(visited, 0, sizeof(visited));
		memset(from, 0, sizeof(from));
		memset(command, 0, sizeof(command));
		memset(path, 0, sizeof(path));
		head = -1;
		scanf("%d %d", &start, &end);
		getchar();
		bfs();
	}
}

