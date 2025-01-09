#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int rsize = 0;
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

void rear_add(Q* q, int num)
{
	if (full(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = num;
	rsize++;
	
}

int rear_pop(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	int prev = q->rear;
	q->rear = (q->rear - 1 + q->size) % q->size;
	if (rsize > 0)
	{
		rsize--;
	}
	return q->q[prev];
}

int rear_peek(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->q[q->rear];
}

void front_add(Q* q, int num)
{
	if (full(q))
	{
		return;
	}
	q->q[q->front] = num;
	q->front = (q->front - 1 + q->size) % q->size;
	rsize++;
}

int front_pop(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	q->front = (q->front + 1) % q->size;
	if (rsize > 0)
	{
		rsize--;
	}
	return q->q[q->front];
}

int front_peek(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->q[(q->front + 1) % q->size];
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Q* ary = create(num);
	for (int i = 0; i < num; i++)
	{
		int get = 0, temp = 0;
		scanf("%d", &get);
		switch (get)
		{
		case 1:
		{
			scanf("%d", &temp);
			front_add(ary, temp);
			break;
		}

		case 2:
		{
			scanf("%d", &temp);
			rear_add(ary, temp);
			break;
		}

		case 3:
		{
			printf("%d\n", front_pop(ary));
			break;
		}

		case 4:
		{
			printf("%d\n", rear_pop(ary));
			break;
		}

		case 5:
		{
			printf("%d\n", rsize);
			break;
		}

		case 6:
		{
			printf("%d\n", empty(ary));
			break;
		}

		case 7:
		{
			printf("%d\n", front_peek(ary));
			break;
		}

		case 8:
		{
			printf("%d\n", rear_peek(ary));
			break;
		}
		}
	}
}