#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define INF 2000000000

int visited[1001] = { 0, };
int mindis[1001] = { 0, };
int path[1001] = { 0, };
int result[1001] = { 0, };

typedef struct Edge
{
	int v;
	int weight;
	struct Edge* link;
}Edge;

Edge* graph[1001];

typedef struct node
{
	int vertex;
	int distance;
}node;

typedef struct Heap
{
	int size;
	node heap[100001];
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
	while ((i != 1) && num.distance < h->heap[i/2].distance)
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

void dijkstra(int start)
{
	Heap* h = create();
	init(h);
	for (int i = 0; i < 1001; i++)
	{
		mindis[i] = INF;
		path[i] = -1;
	}
	mindis[start] = 0;
	node newnode = { start, mindis[start] };
	insert(h, newnode);
	while (h->size > 0)
	{
		node current = delete(h);
		int current_vertex = current.vertex;
		if (visited[current_vertex])
		{
			continue;
		}
		visited[current_vertex] = 1;
		Edge* edge = graph[current_vertex];
		while (edge != NULL)
		{
			int next_vertex = edge->v;
			int weight = edge->weight;
			if (mindis[next_vertex] > mindis[current_vertex] + weight)
			{
				mindis[next_vertex] = mindis[current_vertex] + weight;
				path[next_vertex] = current_vertex;
				node newnode = { next_vertex, mindis[next_vertex] };
				insert(h, newnode);
			}
			edge = edge->link;
		}
	}
}

int main(void)
{
	int vertex = 0, edge = 0, start = 0, end = 0, idx = 0;
	scanf("%d %d", &vertex, &edge);
	getchar();
	for (int i = 0; i < edge; i++)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d %d %d", &u, &v, &w);
		getchar();
		insert_edge(u, v, w);
	}
	scanf("%d %d", &start, &end);
	getchar();
	dijkstra(start);
	printf("%d", mindis[end]);
	return 0;
}
