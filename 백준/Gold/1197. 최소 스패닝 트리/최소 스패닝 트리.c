#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
	int start;
	int end;
	int weight;
}element;

typedef struct Heap
{
	element heap[100010];
	int size;
}Heap;

Heap* init()
{
	Heap* h = (Heap*)malloc(sizeof(Heap));
	h->size = 0;
	return h;
}

void insert(Heap* h, element num)
{
	int i = ++(h->size);
	while ((i != 1) && h->heap[i / 2].weight > num.weight)
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

element delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	element temp = h->heap[h->size--];
	element num = h->heap[1];
	while (child <= h->size)
	{
		if ((child < h->size) && h->heap[child].weight > h->heap[child + 1].weight)
		{
			child++;
		}
		if (temp.weight <= h->heap[child].weight)
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

int parent[10010];
int V = 0, E = 0;
int find(int num)
{
	if (parent[num] == num)
	{
		return num;
	}
	return parent[num] = find(parent[num]);
}

int result = 0;

void kruskal(Heap* h)
{
	int count = 0;
	int aset = 0, bset = 0; // 정점 a와 b의 집합 번호
	while (count < (V - 1))
	{
		element temp = delete(h);
		aset = find(temp.start);
		bset = find(temp.end);
		if (aset != bset)
		{
			count++;
			parent[aset] = bset;
			result += temp.weight;
		}
	}
}

int main(void) // 편의를 위해 각 노드의 루트 값은 자기 자신으로 초기화 하였음.
{
	Heap* h = init();
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; ++i)
	{
		parent[i] = i;
	}
	for (int i = 0; i < E; ++i)
	{
		element temp;
		scanf("%d %d %d", &temp.start, &temp.end, &temp.weight);
		insert(h, temp);
	}
	kruskal(h);
	printf("%d", result);
}