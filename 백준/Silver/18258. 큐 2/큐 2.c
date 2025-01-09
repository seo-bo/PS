#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define real_size 2000001

char get[6];
int rsize = 0;
typedef struct
{
	int front, rear, size;
	int* q;
}Q;

Q* create()
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->size = real_size;
	new->q = (int*)malloc(sizeof(int) * real_size);
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
	rsize++;
}

int pop(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	q->front = (q->front + 1) % q->size;
	rsize--;
	return q->q[q->front];
}

int front_seek(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->q[(q->front + 1) % q->size];
}

int rear_seek(Q* q)
{
	if (empty(q))
	{
		return -1;
	}
	return q->q[q->rear];
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Q * ary = create();
	for (int i = 0; i < num; i++)
	{
		memset(get, 0, sizeof(get));
		scanf("%s", get);

		if (strcmp(get, "push") == 0)
		{
			int temp = 0;
			scanf("%d", &temp);
			add(ary, temp);
		}

		else if (strcmp(get, "pop") == 0)
		{
			printf("%d\n", pop(ary));
		}

		else if (strcmp(get, "size") == 0)
		{
			printf("%d\n", rsize);
		}

		else if (strcmp(get, "empty") == 0)
		{
			printf("%d\n", empty(ary));
		}

		else if (strcmp(get, "front") == 0)
		{
			printf("%d\n", front_seek(ary));
		}

		else if (strcmp(get, "back") == 0)
		{
			printf("%d\n", rear_seek(ary));
		}
	}
}