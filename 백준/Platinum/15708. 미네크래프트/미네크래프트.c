#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int N = 0, T = 0, P = 0;

typedef struct Heap
{
	int size;
	int heap[100001];
}Heap;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

void init(Heap* h)
{
	h->size = 0;
}

void insert(Heap* h, int num)
{
	int i = ++(h->size);
	while ((i != 1) && num > h->heap[i / 2])
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

int delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	int num = h->heap[1];
	int temp = h->heap[h->size--];
	while (child <= h->size)
	{
		if ((child < h->size) && h->heap[child] < h->heap[child + 1])
		{
			child++;
		}
		if (temp >= h->heap[child])
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

int Max(int num1, int num2)
{
	return (num1 < num2) ? num2 : num1;
}

int main(void)
{
	Heap* h = create();
	init(h);
	int sum = 0, result = 0, count = 0, temp = 0;
	scanf("%d %d %d", &N, &T, &P);
	getchar();
	for (int i = 0; i < N; i++)
	{
		if (T - i * P < 0)
		{
			printf("%d", result);
			return 0;
		}
		scanf("%d", &temp);
		getchar();
		sum += temp;
		insert(h, temp);
		count++;
		while (sum > T - i * P) // T - i * P이하로 하면서 최대한 많이 합쳐야함
		{
			sum -= delete(h);
			count--;
		}
		result = Max(result, count);
	}
	printf("%d", result);
}