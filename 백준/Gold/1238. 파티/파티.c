#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define INF 2000000000

int visited[1001] = { 0, };
int front_mindis[1001] = { 0, };
int back_mindis[1001] = { 0, };

typedef struct Edge
{
	int v;
	int weight;
	struct Edge* link;
}Edge;

Edge* front_graph[1001];
Edge* back_graph[1001];

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

void front_insert_edge(int u, int v, int w)
{
	Edge* new = (Edge*)malloc(sizeof(Edge));
	new->v = v;
	new->weight = w;
	new->link = front_graph[u];
	front_graph[u] = new;
}

void back_insert_edge(int u, int v, int w)
{
	Edge* new = (Edge*)malloc(sizeof(Edge));
	new->v = v;
	new->weight = w;
	new->link = back_graph[u];
	back_graph[u] = new;
}

void front_dijkstra(int start)
{
	memset(visited, 0, sizeof(visited));
	Heap* h = create();
	init(h);
	for (int i = 0; i < 1001; i++)
	{
		front_mindis[i] = INF;
	}
	front_mindis[start] = 0;
	node newnode = { start, front_mindis[start] };
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
		Edge* edge = front_graph[current_vertex];
		while (edge != NULL)
		{
			int next_vertex = edge->v;
			int weight = edge->weight;
			if (front_mindis[next_vertex] > front_mindis[current_vertex] + weight)
			{
				front_mindis[next_vertex] = front_mindis[current_vertex] + weight;
				node newnode = { next_vertex, front_mindis[next_vertex] };
				insert(h, newnode);
			}
			edge = edge->link;
		}
	}
	free(h);
}

void back_dijkstra(int start)
{
	memset(visited, 0, sizeof(visited));
	Heap* h = create();
	init(h);
	for (int i = 0; i < 1001; i++)
	{
		back_mindis[i] = INF;
	}
	back_mindis[start] = 0;
	node newnode = { start, back_mindis[start] };
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
		Edge* edge = back_graph[current_vertex];
		while (edge != NULL)
		{
			int next_vertex = edge->v;
			int weight = edge->weight;
			if (back_mindis[next_vertex] > back_mindis[current_vertex] + weight)
			{
				back_mindis[next_vertex] = back_mindis[current_vertex] + weight;
				node newnode = { next_vertex, back_mindis[next_vertex] };
				insert(h, newnode);
			}
			edge = edge->link;
		}
	}
	free(h);
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int vertex = 0, edge = 0, machi = 0, result = 0;
	scanf("%d %d %d", &vertex, &edge, &machi);
	getchar();
	for (int i = 0; i < edge; i++)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d %d %d", &u, &v, &w);
		getchar();
		front_insert_edge(u, v, w);
		back_insert_edge(v, u, w);

	}
	front_dijkstra(machi);
	back_dijkstra(machi);
	for (int i = 0; i <= vertex; i++)
	{
		if (front_mindis[i] != INF && back_mindis[i] != INF)
		{
			result = Max(result, front_mindis[i] + back_mindis[i]);
		}
	}
	printf("%d", result);
	return 0;
}