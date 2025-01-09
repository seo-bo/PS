#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int heap[100001];
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

void insert_min(Heap* h, int num)
{
	int i = ++(h->size);
	while ((i != 1) && (num < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

int delete_min(Heap* h)
{
	if (h->size == 0)
	{
		return 0;
	}
	int parent = 1, child = 2;
	int num = h->heap[1];
	int temp = h->heap[(h->size)--];
	while (child <= h->size)
	{
		if ((child < h->size) && (h->heap[child] > h->heap[child + 1]))
		{
			child++;
		}
		if (temp <= h->heap[child])
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
	
int main(void)
{
	Heap* h = create();
	init(h);
	int test = 0;
	scanf("%d", &test);
	getchar();
	for (int i = 0; i < test; i++)
	{
		int get = 0;
		scanf("%d", &get);
		getchar();
		if (get == 0)
		{
			printf("%d\n", delete_min(h));
		}
		else
		{
			insert_min(h, get);
		}
	}
	free(h);
}

