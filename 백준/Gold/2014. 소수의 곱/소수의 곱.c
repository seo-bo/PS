#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Heap
{
	long long heap[10000010];
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

void insert_min(Heap* h, long long num)
{
	int i = ++(h->size);
	while ((i != 1) && (num < h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

long long delete_min(Heap* h)
{
	int parent = 1, child = 2;
	long long num = h->heap[1];
	long long temp = h->heap[(h->size)--];
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
	long long num = 0, count = 0;
	scanf("%lld %lld", &num, &count);
	long long* ary = (long long*)calloc(num, sizeof(long long));
	for (int i = 0; i < num; i++)
	{
		scanf("%lld", &ary[i]);
		insert_min(h, ary[i]);
	}
	long long temp = 0;
	for (int i = 0; i < count; i++)
	{
		temp = delete_min(h);
		for (int j = 0; j < num; j++)
		{
			long long get = temp * ary[j];
			if (get > 2147483647)
			{
				break;
			}
			insert_min(h, get);
			if (temp % ary[j] == 0)
			{
				break;
			}
		} 
	}
	printf("%lld", temp);
}