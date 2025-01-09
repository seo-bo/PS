#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define INF 1000000000
typedef struct Edge
{
	int v;
	int weight;
	struct Edge* link;
}Edge;

Edge* graph[1001];
int visited[1001] = { 0, };
int mindis[1001] = { 0, };
int path[1001] = { 0, };
int result[1001] = { 0, };
typedef struct node
{
	int number;
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
	node temp = h->heap[h->size--];
	node num = h->heap[1];
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
	node newone = { start, mindis[start] };
	insert(h, newone);
	while (h->size > 0)
	{
		node current = delete(h);
		int current_vertex = current.number;
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
				node nextnode = { next_vertex, mindis[next_vertex] };
				insert(h, nextnode);
			}
			edge = edge->link;
		}
	}
	free(h);
}

int main(void)
{
	memset(graph, 0, sizeof(graph));
	int vertex = 0, edge = 0, start = 0, end = 0, idx = 0;
	scanf("%d %d", &vertex, &edge);
	getchar();
	for (int i = 0; i < edge; i++)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d %d %d", &u, &v, &w);
		insert_edge(u, v, w);
	}
	scanf("%d %d", &start, &end);
	getchar();
	dijkstra(start);
	printf("%d\n", mindis[end]);
	for (int i = end; i != -1; i = path[i])
	{
		result[idx++] = i;
	}
	printf("%d\n", idx);
	for (int i = idx - 1; i >= 0; --i) 
	{
		printf("%d ", result[i]);
	}
	return 0;
}