#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct Heap
{
	int maxheap[50001];
	int minheap[50001];
	int maxsize;
	int minsize;
}Heap;

Heap* create()
{
	Heap*h = (Heap*)malloc(sizeof(Heap));
	h->minsize = 0;
	h->maxsize = 0;
	return h;
}

void insert_min(Heap* h, int num)
{
	int i = ++(h->minsize);
	while ((i != 1) && (num < h->minheap[i / 2]))
	{
		h->minheap[i] = h->minheap[i / 2];
		i /= 2;
	}
	h->minheap[i] = num;
}

void insert_max(Heap* h, int num)
{
	int i = ++(h->maxsize);
	while ((i != 1) && (num > h->maxheap[i / 2]))
	{
		h->maxheap[i] = h->maxheap[i / 2];
		i /= 2;
	}
	h->maxheap[i] = num;
}

int delete_max(Heap* h)
{
	int parent = 1, child = 2;
	int num = h->maxheap[1];
	int temp = h->maxheap[(h->maxsize)--];
	while (child <= h->maxsize)
	{
		if ((child < h->maxsize) && (h->maxheap[child] < h->maxheap[child + 1]))
		{
			child++;
		}
		if (temp >= h->maxheap[child])
		{
			break;
		}
		else
		{
			h->maxheap[parent] = h->maxheap[child];
			parent = child;
			child *= 2;
		}
	}
	h->maxheap[parent] = temp;
	return num;
}

int delete_min(Heap* h)
{
	int parent = 1, child = 2;
	int num = h->minheap[1];
	int temp = h->minheap[(h->minsize)--];
	while (child <= h->minsize)
	{
		if ((child < h->minsize) && (h->minheap[child] > h->minheap[child + 1]))
		{
			child++;
		}
		if (temp <= h->minheap[child])
		{
			break;
		}
		else
		{
			h->minheap[parent] = h->minheap[child];
			parent = child;
			child *= 2;
		}
	}
	h->minheap[parent] = temp;
	return num;
}

void balance(Heap* h)
{
	while (h->maxsize > h->minsize + 1)
	{
		insert_min(h, delete_max(h));
	}
	while (h->maxsize < h->minsize)
	{
		insert_max(h, delete_min(h));
	}
}

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	getchar();
	Heap* h = create();
	for (int i = 0; i < test; i++)
	{
		int get = 0;
		scanf("%d", &get);
		if (h->maxsize == 0 || h->maxheap[1] >= get)
		{
			insert_max(h, get);
		}
		else
		{
			insert_min(h, get);
		}
		balance(h);
		printf("%d\n", h->maxheap[1]);
	}
	free(h);
}
