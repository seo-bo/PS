#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Planet
{
	int x;
	int y;
	int z;
	int idx;
}Planet;

typedef struct Edge
{
	int cost;
	int u;
	int v;
}Edge;

Planet planet[100001];
Edge edge[300001];
int parent[100001];

int compare_x(const void* num1, const void* num2)
{
	return ((Planet*)num1)->x - ((Planet*)num2)->x;
}

int compare_y(const void* num1, const void* num2)
{
	return ((Planet*)num1)->y - ((Planet*)num2)->y;
}

int compare_z(const void* num1, const void* num2)
{
	return ((Planet*)num1)->z - ((Planet*)num2)->z;
}

int compare_edge(const void* num1, const void* num2)
{
	return ((Edge*)num1)->cost - ((Edge*)num2)->cost;
}

int find(int num)
{
	if (num == parent[num])
	{
		return num;
	}
	return parent[num] = find(parent[num]);
}

void Union(int num1, int num2)
{
	num1 = find(num1);
	num2 = find(num2);
	parent[num1] = num2;
}

int main(void)
{
	int num = 0, line = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		planet[i].idx = i;
		scanf("%d %d %d", &planet[i].x, &planet[i].y, &planet[i].z);
		parent[i] = i;
	}
	qsort(planet, num, sizeof(Planet), compare_x);
	for (int i = 0; i < num - 1; i++)
	{
		edge[line].cost = abs(planet[i].x - planet[i + 1].x);
		edge[line].u = planet[i].idx;
		edge[line++].v = planet[i + 1].idx;
	}
	qsort(planet, num, sizeof(Planet), compare_y);
	for (int i = 0; i < num - 1; i++)
	{
		edge[line].cost = abs(planet[i].y - planet[i + 1].y);
		edge[line].u = planet[i].idx;
		edge[line++].v = planet[i + 1].idx;
	}
	qsort(planet, num, sizeof(Planet), compare_z);
	for (int i = 0; i < num - 1; i++)
	{
		edge[line].cost = abs(planet[i].z - planet[i + 1].z);
		edge[line].u = planet[i].idx;
		edge[line++].v = planet[i + 1].idx;
	}
	qsort(edge, line, sizeof(Edge), compare_edge);
	long long result = 0;
	for (int i = 0; i < line; i++)
	{
		if (find(edge[i].u) != find(edge[i].v))
		{
			Union(edge[i].u, edge[i].v);
			result += edge[i].cost;
		}
	}
	printf("%lld", result);
}
