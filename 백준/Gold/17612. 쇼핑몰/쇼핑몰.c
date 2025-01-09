#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Shop
{
	int number;
	int minute;
	int cash;
}Shop;

typedef struct Heap
{
	int size;
	Shop heap[100001];
}Heap;

typedef struct Order
{
	int size;
	int heap[100001];
}Order;

Heap* create()
{
	return (Heap*)malloc(sizeof(Heap));
}

Order* o_create()
{
	return (Order*)malloc(sizeof(Order));
}

void init(Heap* h)
{
	h->size = 0;
}

void o_init(Order* o)
{
	o->size = 0;
}

void insert(Heap* h, Shop num)
{
	int i = ++(h->size);
	while ((i != 1) && (num.minute < h->heap[i / 2].minute || (num.minute == h->heap[i / 2].minute && num.cash > h->heap[i / 2].cash)))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = num;
}

void o_insert(Order* o, int num)
{
	int i = ++(o->size);
	while ((i != 1) && (num < o->heap[i / 2]))
	{
		o->heap[i] = o->heap[i / 2];
		i /= 2;
	}
	o->heap[i] = num;
}

Shop delete(Heap* h)
{
	int parent = 1;
	int child = 2;
	Shop num = h->heap[1];
	Shop temp = h->heap[(h->size)--];
	while (child <= h->size)
	{
		if ((child < h->size) && (h->heap[child].minute > h->heap[child + 1].minute || (h->heap[child].minute == h->heap[child + 1].minute && h->heap[child].cash < h->heap[child + 1].cash)))
		{
			child++;
		}
		if (temp.minute < h->heap[child].minute || (temp.minute == h->heap[child].minute && temp.cash > h->heap[child].cash))
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

int o_delete(Order* o)
{
	int parent = 1;
	int child = 2;
	int num = o->heap[1];
	int temp = o->heap[(o->size)--];
	while (child <= o->size)
	{
		if ((child < o->size) && (o->heap[child] > o->heap[child + 1]))
		{
			child++;
		}
		if (temp <= o->heap[child])
		{
			break;
		}
		o->heap[parent] = o->heap[child];
		parent = child;
		child *= 2;
	}
	o->heap[parent] = temp;
	return num;
}

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	Heap* h = create();
	Order* o = o_create();
	init(h);
	o_init(o);
	int num = 0, casher = 0;
	long long k = 1;
	long long result = 0;
	scanf("%d %d", &num, &casher);
	getchar();
	Shop* ary = (Shop*)malloc(sizeof(Shop) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].number, &ary[i].minute);
		getchar();
	}
	int min = Min(num, casher);
	for (int i = 0; i < min; i++)
	{
		ary[i].cash = i + 1;
		insert(h, ary[i]);
	}
	for (int i = casher; i < num;)
	{
		Shop temp = h->heap[1];
		while (temp.minute == h->heap[1].minute && h->size > 0)
		{
			Shop cnt = delete(h);
			result += k * (long long)cnt.number;
			k++;
			o_insert(o, cnt.cash);
		}
		while (o->size > 0 && i < num)
		{
			ary[i].cash = o_delete(o);
			ary[i].minute += temp.minute;
			insert(h, ary[i]);
			i++;
		}
	}
	while (h->size > 0)
	{
		Shop temp = delete(h);
		result += k * (long long)temp.number;
		k++;
	}
	printf("%lld", result);
}