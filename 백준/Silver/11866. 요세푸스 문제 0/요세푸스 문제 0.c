#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct
{
	int front, rear, size;
	int* q;
}Q;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->size = size + 1;
	new->q = (int*)malloc(sizeof(int) * (size + 2));
	return new;
}

int full(Q* q)
{
	return q->front == (q->rear + 1) % q->size;
}

int empty(Q* q)
{
	return q->front == q->rear;
}

void add(Q* q, int num)
{
	if (full(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = num;
}

int size(Q* q)
{
	if (q->front < q->rear)
	{
		return q->rear - q->front;
	}
	else
	{
		return q->size - q->front + q->rear;
	}
}

int pop(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	q->front = (q->front + 1) % q->size;
	return q->q[q->front];
}


int main(void)
{
	int num = 0, which = 0;
	scanf("%d %d", &num, &which);
	Q* ary = create(num);
	for (int i = 1; i <= num; i++)
	{
		add(ary, i);
	}
	printf("<");
	for (int i = 0; i < num; i++)
	{
		for (int j = 1; j < which; j++)
		{
			add(ary, pop(ary));
		}
		if (size(ary) == 1)
		{
			break;
		}
		printf("%d, ", pop(ary));
	}
	printf("%d>", pop(ary));
	free(ary->q);
	free(ary);
}