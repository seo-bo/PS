#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct element
{
	int value;
	int space;
}element;

typedef struct Q
{
	int front, rear, size;
	element* q;
}Q;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = new->rear = 0;
	new->size = size + 2;
	new->q = (element*)malloc(sizeof(element) * new->size);
	return new;
}

int empty(Q* q)
{
	return q->front == q->rear;
}

void front_push(Q* q, int value, int space)
{
	q->q[q->front].value = value;
	q->q[q->front].space = space;
	q->front = (q->front - 1 + q->size) % q->size;
}

void rear_push(Q* q, int value, int space)
{
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear].value = value;
	q->q[q->rear].space = space;
}

void front_pop(Q* q)
{
	if (empty(q))
	{
		return;
	}
	q->front = (q->front + 1) % q->size;
}

void rear_pop(Q* q)
{
	if (empty(q))
	{
		return;
	}
	int temp = q->rear;
	q->rear = (q->rear - 1 + q->size) % q->size;
}

int main(void)
{
	int num = 0, range = 0;
	scanf("%d %d", &num, &range);
	getchar();
	int* ary = (int*)calloc((num + 1), sizeof(int));
	Q* q = create(num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 1; i <= num; i++)
	{
		if (!empty(q))
		{
			if (q->q[(q->front + 1) % q->size].space < i - range + 1)
			{
				front_pop(q);
			}
		}
		while (!empty(q) && q->q[q->rear].value > ary[i])
		{
			rear_pop(q);
		}
		rear_push(q, ary[i], i);
		printf("%d ", q->q[(q->front + 1) % q->size].value);
	}
}