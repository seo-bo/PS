#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct Class
{
	int start;
	int end;
}Class;

typedef struct Heap
{
	int size;
	Class heap[200001];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}

void insert(Heap* h, Class num)
{
	int i = ++(h->size);
	while ((i != 1) && num.end < h->heap[i / 2].end)
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

Class delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	Class num = h->heap[1];
	Class temp = h->heap[h->size--];
	while (child <= h->size)
	{
		if ((child < h->size) && h->heap[child].end > h->heap[child + 1].end)
		{
			child++;
		}
		if (temp.end <= h->heap[child].end)
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

int compare(const void* num1, const void* num2)
{
	if (((Class*)num1)->start == ((Class*)num2)->start)
	{
		return ((Class*)num2)->end - ((Class*)num1)->end;
	}
	else
	{
		return ((Class*)num1)->start - ((Class*)num2)->start;
	}
}

int main(void)
{
	Heap* h = create();
	init(h);
	int num = 0;
	scanf("%d", &num);
	Class* ary = (Class*)malloc(sizeof(Class) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].start, &ary[i].end);
	}
	qsort(ary, num, sizeof(Class), compare);
	insert(h, ary[0]);
	for (int i = 1; i < num; i++)
	{
		if (ary[i].start >= h->heap[1].end)
		{
			delete(h);
			insert(h, ary[i]);
		}
		else
		{
			insert(h, ary[i]);
		}
	}
	printf("%d", h->size);
}