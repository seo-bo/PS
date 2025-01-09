#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define rsize 500001

typedef struct
{
	int front, rear;
	int* q;
}Q;

Q* create()
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->q = (int*)malloc(sizeof(int) * rsize);
	return new;
}

int full(Q* q)
{
	return q->front == ((q->rear + 1) % rsize) ;
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
	q->rear = (q->rear + 1) % rsize;
	q->q[q->rear] = num;
}
int pop(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	q->front = (q->front + 1) % rsize;
	return q->q[q->front];
}

int main(void)
{
	int num = 0, result = 0;
	scanf("%d", &num);
	Q * ary = create();
	for (int i = 0; i < num; i++)
	{
		add(ary, i + 1);
	}
	while (!empty(ary))
	{
		result = pop(ary);
		if (empty(ary))
		{
			break;
		}
		result = pop(ary);
		add(ary, result);
	}
	printf("%d", result);
}