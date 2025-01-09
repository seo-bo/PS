#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct element
{
	int weight;
	int value;
}element;

element jewel[300001];
int knap[300001] = { 0, };

typedef struct Heap
{
	element heap[300001];
	int size;
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}

void insert_max(Heap* h, int value)
{
	int i = ++(h->size);
	while ((i != 1) && (value > h->heap[i / 2].value))
	{
		h->heap[i].value = h->heap[i / 2].value;
		i /= 2;
	}
	h->heap[i].value = value;
}

int delete_max(Heap* h)
{
	int parent = 0, child = 0;
	int item, temp;
	item = h->heap[1].value;
	temp = h->heap[(h->size)--].value;
	parent = 1;
	child = 2;
	while (child <= h->size)
	{
		if ((child < h->size) && h->heap[child].value < h->heap[child + 1].value)
		{
			child++;
		}
		if (temp >= h->heap[child].value)
		{
			break;
		}
		h->heap[parent].value = h->heap[child].value;
		parent = child;
		child *= 2;
	}
	h->heap[parent].value = temp;
	return item;
}

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int compare_jewel(const void* num1, const void* num2)
{
	
	return ((element*)num1)->weight - ((element*)num2)->weight;
}


int main(void)
{
	int num = 0, pack = 0;
	scanf("%d %d", &num, &pack);
	getchar();
	Heap* h = create();
	init(h);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &jewel[i].weight, &jewel[i].value);
	}
	for (int i = 0; i < pack; i++)
	{
		scanf("%d", &knap[i]);
	}
	qsort(jewel, num, sizeof(jewel[0]), compare_jewel);
	qsort(knap, pack, sizeof(int), compare);
	long long result = 0;
	int idx = 0;
	for (int i = 0; i < pack; i++)
	{
		while (idx < num && jewel[idx].weight <= knap[i])
		{
			insert_max(h, jewel[idx].value);
			idx++;
		}
		if (h->size != 0)
		{
			result += (long long)delete_max(h);
		}
	}
    free(h);
	printf("%lld", result);
}