#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define INF 2000000000

int foxdis[4001] = { 0, };
int wolfdis[4001][2] = { 0, };
int vertex = 0, edge = 0;
typedef struct Edge
{
	int v;
	int weight;
	struct Edge* link;
}Edge;

Edge* graph[4001];

typedef struct node
{
	int vertex;
	int distance;
	int fast;
}node;

typedef struct Heap
{
	int size;
	node heap[200001];
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
		if ((child < h->size) && (h->heap[child].distance > h->heap[child + 1].distance))
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

void fox()
{
	Heap* h = create();
	init(h);
	for (int i = 1; i <= vertex; i++)
	{
		foxdis[i] = INF;
	}
	foxdis[1] = 0;
	node newnode = { 1, 0 };
	insert(h, newnode);
	while (h->size > 0)
	{
		node current = delete(h);
		int current_vertex = current.vertex;
		int current_distance = current.distance;
		if (foxdis[current_vertex] < current.distance)
		{
			continue;
		}
		Edge* edge = graph[current_vertex];
		while (edge != NULL)
		{
			int next_vertex = edge->v;
			int next_distance = edge->weight + current_distance;
			if (foxdis[next_vertex] > next_distance)
			{
				foxdis[next_vertex] = next_distance;
				node newnode = { next_vertex, next_distance};
				insert(h, newnode);
			}
			edge = edge->link;
		}
	}
	free(h);
}

void wolf()
{
	Heap* h = create();
	init(h);
	for (int i = 1; i <= vertex; i++)
	{
		wolfdis[i][0] = INF;
		wolfdis[i][1] = INF;
	} //한바퀴 돌아올 수도 있으니까 wolfdis 초기화 하지 말기?
	node newnode = { 1, 0 , 0 };
	insert(h, newnode);
	while (h->size > 0)
	{
		node current = delete(h);
		int current_vertex = current.vertex;
		int current_distance = current.distance;
		int current_fast = current.fast;
		if (wolfdis[current_vertex][(current_fast + 1) % 2] < current_distance)
		{
			continue;
		}
		Edge* edge = graph[current_vertex];
		while (edge != NULL)//만약 fast가 0이면 (/2) 1이면 (*2)
		{
			int next_vertex = edge->v;
			if (current_fast == 0)
			{
				int next_distance = current_distance + (edge->weight / 2);
				if (wolfdis[next_vertex][0] > next_distance)
				{
					wolfdis[next_vertex][0] = next_distance;
					node newnode = { next_vertex, next_distance, 1 };
					insert(h, newnode);
				}
			}
			else if (current_fast == 1)
			{
				int next_distance = current_distance + (edge->weight * 2);
				if (wolfdis[next_vertex][1] > next_distance)
				{
					wolfdis[next_vertex][1] = next_distance;
					node newnode = { next_vertex, next_distance, 0 };
					insert(h, newnode);
				}
			}
			edge = edge->link;
		}
	}
	free(h);
}

int Min(int num1, int num2)
{
	return (num1 < num2) ? num1 : num2;
}

int main(void)
{
	int count = 0;
	scanf("%d %d", &vertex, &edge);
	getchar();
	for (int i = 0; i < edge; i++)
	{
		int u = 0, v = 0, w = 0;
		scanf("%d %d %d", &u, &v, &w);
		getchar();
		insert_edge(u, v, 2 * w);
		insert_edge(v, u, 2 * w);
	}
	fox();
	wolf();
	for (int i = 2; i <= vertex; i++)
	{
		if (foxdis[i] < Min(wolfdis[i][0], wolfdis[i][1]))
		{
			count++;
		}
	}
	printf("%d", count);
}
