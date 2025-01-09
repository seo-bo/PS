#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Gas
{
	int idx;
	int fuel;
}Gas;

typedef struct Heap
{
	int size;
	Gas heap[10005];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}

void insert(Heap* h, Gas num)
{
	int i = ++(h->size);
	while ((i != 1) && num.fuel > h->heap[i / 2].fuel)
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

Gas delete(Heap* h)
{
	int parent = 1, child = 2;
	Gas num = h->heap[1];
	Gas temp = h->heap[(h->size)--];
	while (child <= h->size)
	{
		if ((child < h->size) && h->heap[child].fuel < h->heap[child + 1].fuel)
		{
			child++;
		}
		if (temp.fuel >= h->heap[child].fuel)
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
	return ((Gas*)num1)->idx - ((Gas*)num2)->idx;
}

int main(void)
{
	int count = 0;
	Heap* h = create();
	init(h);
	Gas dest;
	int num = 0;
	scanf("%d", &num);
	getchar();
	Gas* ary = (Gas*)malloc(sizeof(Gas) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].idx, &ary[i].fuel);
		getchar();
	}
	qsort(ary, num, sizeof(Gas), compare);
	scanf("%d %d", &dest.idx, &dest.fuel);
	getchar();
	for (int i = 0; i < num;)
	{
		if (ary[i].idx <= dest.fuel)
		{
			insert(h, ary[i]);
			i++;
		}
		else
		{
			while (ary[i].idx > dest.fuel && h->size != 0)
			{
				dest.fuel += delete(h).fuel;
				count++;
			}
			if (ary[i].idx > dest.fuel)
			{
				printf("-1");
				return 0;
			}
		}
	}
	if (dest.idx > dest.fuel)
	{
		while (h->size != 0 && dest.idx > dest.fuel)
		{
			dest.fuel += delete(h).fuel;
			count++;
		}
		if (dest.idx > dest.fuel)
		{
			printf("-1");
			return 0;
		}
		else
		{
			printf("%d", count);
		}
	}
	else
	{
		printf("%d", count);
	}
}