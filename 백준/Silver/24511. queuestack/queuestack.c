#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int get[100001] = { 0, };

typedef struct
{
	int front, rear, size;
	int* q;
}Q;

Q* create(int num)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = num;
	new->size = num + 1;
	new->q = malloc(sizeof(int) * (num + 1));
	return new;
}

void push(Q* q, int num)
{
	q->q[q->front] = num;
	q->front = (q->front - 1 + q->size) % q->size;
}

int pop(Q* q)
{
	int prev = q->q[q->rear];
	q->rear = (q->rear - 1 + q->size) % q->size;
	return prev;
}

int main(void) 
{
	int num = 0, count = 0, k = 1;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &get[i]);
		if (get[i] == 0)
		{
			count++;
		}
	}
	if (count == 0)
	{
		for (int i = 0; i < num; i++)
		{
			int temp = 0;
			scanf("%d", &temp);
		}
		int test = 0;
		scanf("%d", &test);
		for (int i = 0; i < test; i++)
		{
			int temp = 0;
			scanf("%d", &temp);
			printf("%d ", temp);
		}
	}
	else
	{
		Q* ary = create(count);
		for (int i = 0; i < num; i++)
		{
			int temp = 0;
			scanf("%d", &temp);
			if (get[i] == 0)
			{
				ary->q[k] = temp;
				k++;
			}
		}
		int test = 0;
		scanf("%d", &test);
		for (int i = 0; i < test; i++)
		{
			int put = 0;
			scanf("%d", &put);
			push(ary,put);
			printf("%d ", pop(ary));
		}
		free(ary->q);
		free(ary);
	}
}
