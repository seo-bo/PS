#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define INF 1000000000

int visited[202][202] = { 0, };
int mindis[202][202] = { 0, };
int first_visit[202][202] = { 0, };

typedef struct Edge
{
	int v;
	int weight;
	struct Edge* link;
}Edge;

Edge* graph[201];

typedef struct node
{
	int vertex;
	int distance;
}node;

typedef struct Heap
{
	int size;
	node heap[10001];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}

void insert(Heap* h, node num)
{
	int i = ++(h->size);
	while ((i != 1) && num.distance < h->heap[i / 2].distance)
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

node delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	node num = h->heap[1];
	node temp = h->heap[h->size--];
	while (child <= h->size)
	{
		if ((child < h->size) && h->heap[child].distance > h->heap[child + 1].distance)
		{
			child++;
		}
		if (temp.distance <= h->heap[child].distance)
		{
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return num;
}

void insert_edge(int u, int v, int w)
{
	Edge* new = (Edge*)malloc(sizeof(Edge));
	new->v = v;
	new->weight = w;
	new->link = graph[u];
	graph[u] = new;
}

void dijkstra(int start, int vertex)
{
	Heap* h = create();
	init(h);
	for (int i = 1; i <= vertex; i++)
	{
		mindis[start][i] = INF;
		first_visit[start][i] = -1;
	}
	mindis[start][start] = 0;
	node newnode = { start, mindis[start][start] };
	insert(h, newnode);
	while (h->size > 0)
	{
		node current = delete(h);
		int current_vertex = current.vertex;
		if (visited[start][current_vertex])
		{
			continue;
		}
		visited[start][current_vertex] = 1;
		Edge* edge = graph[current_vertex];
		while (edge != NULL)
		{
			int next_vertex = edge->v;
			int weight = edge->weight;
			if (mindis[start][next_vertex] > mindis[start][current_vertex] + weight)
			{
				mindis[start][next_vertex] = mindis[start][current_vertex] + weight;
				node newnode = { next_vertex, mindis[start][next_vertex] };
				insert(h, newnode);
				first_visit[start][next_vertex] = (current_vertex == start) ? next_vertex : first_visit[start][current_vertex];
			}
			edge = edge->link;
		}
	}
	free(h);
}

int main(void)
{
	int vertex = 0, edge = 0;
	scanf("%d %d", &vertex, &edge);
	for (int i = 0; i < edge; i++)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d %d %d", &u, &v, &w);
		getchar();
		insert_edge(u, v, w);
		insert_edge(v, u, w);
	}
	for (int i = 1; i <= vertex; i++)
	{
		dijkstra(i, vertex);
	}
	for (int i = 1; i <= vertex; i++)
	{
		for (int j = 1; j <= vertex; j++)
		{
			if (i == j)
			{
				printf("- ");
			}
			else
			{
				printf("%d ", first_visit[i][j]);
			}
		}
		printf("\n");
	}
}