#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int visited[1001] = { 0, };

typedef struct Q
{
	int front, rear, size;
	int* q;
}Q;

typedef struct Node
{
	int vertex;
	struct Node* link;
}Node;

typedef struct Graph
{
	int n;
	Node* list[1001];
}Graph;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->size = size + 1;
	new->q = (int*)malloc(sizeof(int) * new->size);
	return new;
}

int empty(Q* q)
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

void init(Graph* g)
{
	g->n = 0;
	for (int i = 0; i < 1001; i++)
	{
		g->list[i] = 0;
	}
}

void insert_vertex(Graph* g, int vertex)
{
	g->n = vertex;
}

void insert_edge(Graph* g, int start, int end)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->vertex = end;
	Node** current = &(g->list[start]);
	while (*current && (*current)->vertex < end)
	{
		current = &((*current)->link);
	}
	new->link = *current;
	*current = new;
}

void dfs(Graph* g, int start)
{
	visited[start] = 1;
	printf("%d ", start);
	for (Node* i = g->list[start]; i; i = i->link)
	{
		if (!visited[i->vertex])
		{
			dfs(g, i->vertex);
		}
	}
}

void bfs(Graph* g, int start, int size)
{
	Q* q = create(size);
	memset(visited, 0, sizeof(visited));
	visited[start] = 1;
	enqueue(q, start);
	while (!empty(q))
	{
		start = dequeue(q);
		printf("%d ", start);
		for (Node* i = g->list[start]; i; i = i->link)
		{
			if (!visited[i->vertex])
			{
				visited[i->vertex] = 1;
				enqueue(q, i->vertex);
			}
		}
	}
	free(q);
}

int main(void)
{
	int vertex = 0, edge = 0, start = 0;
	scanf("%d %d %d", &vertex, &edge, &start);
	getchar();
	Graph* g = (Graph*)malloc(sizeof(Graph));
	init(g);
	insert_vertex(g, vertex);
	for (int i = 0; i < edge; i++)
	{
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		getchar();
		insert_edge(g, num1, num2);
		insert_edge(g, num2, num1);
	}
	dfs(g, start);
	printf("\n");
	bfs(g, start, vertex);
	free(g);
}