#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int visited[101] = { 0, };

typedef struct Node
{
	int vertex;
	struct Node* link;
}Node;

typedef struct Graph
{
	int n;
	Node* list[101];
}Graph;

void init(Graph* g, int vertex)
{
	g->n = vertex;
	for (int i = 0; i <= vertex; i++)
	{
		g->list[i] = 0;
	}
}

void insert_edge(Graph* g, int start, int end)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->vertex = end;
	new->link = g->list[start];
	g->list[start] = new;
}

void dfs(Graph* g, int start)
{
	visited[start] = 1;
	for (Node* i = g->list[start]; i; i = i->link)
	{
		if (!visited[i->vertex])
		{
			dfs(g, i->vertex);
		}
	}
}

int main(void)
{
	int num = 0, count = 0;
	scanf("%d", &num);
	Graph* g = (Graph*)malloc(sizeof(Graph));
	init(g, num);
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int temp1 = 0, temp2 = 0;
		scanf("%d %d", &temp1, &temp2);
		getchar();
		insert_edge(g, temp1, temp2);
		insert_edge(g, temp2, temp1);
	}
	dfs(g, 1);
	for (int i = 2; i <= num; i++)
	{
		if (visited[i])
		{
			count++;
		}
	}
	printf("%d", count);
}