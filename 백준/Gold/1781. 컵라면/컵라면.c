#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct Ramen
{
	int deadline;
	int get;
}Ramen;

typedef struct Heap
{
	int size;
	Ramen heap[200010];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}

void insert(Heap* h, Ramen num)
{
	int i = ++(h->size);
	while ((i != 1) && (num.get < h->heap[i / 2].get))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

Ramen delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	Ramen num = h->heap[1];
	Ramen temp = h->heap[(h->size)--];
	while (child <= h->size)
	{
		if (child < h->size && (h->heap[child].get > h->heap[child + 1].get))
		{
			child++;
		}
		if (temp.get <= h->heap[child].get)
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
	return ((Ramen*)num1)->deadline - ((Ramen*)num2)->deadline;
}

int main(void)
{
	Heap* h = create();
	init(h);
	int num = 0; 
	long long result = 0;
	scanf("%d", &num);
	getchar();
	Ramen* ary = (Ramen*)malloc(sizeof(Ramen) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].deadline, &ary[i].get);
		getchar();
	}
	qsort(ary, num, sizeof(Ramen), compare);
	for (int i = 0; i < num; i++)
	{
		if (h->size < ary[i].deadline)
		{
			insert(h, ary[i]);
		}
		else if (h->size >= ary[i].deadline && h->heap[1].get < ary[i].get)
		{
			delete(h);
			insert(h, ary[i]);
		}
	}
	while (h->size > 0)
	{
		result += delete(h).get;
	}
	printf("%lld", result);
}