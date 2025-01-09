#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[100001];
int inter[100001];
char get[400002];
typedef struct
{
	int front, rear, size;
	int* q;
}Q;

Q* create(int size)
{
	Q* new = malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->size = size + 2;
	new->q = malloc(sizeof(int) * (size + 2));
	return new;
}

void swap(Q* q)
{
	int temp = q->front;
	q->front = q->rear;
	q->rear = temp;
}

int empty(Q* q)
{
	return q->front == q->rear;
}

int full(Q* q)
{
	return q->front == (q->rear + 1) % q->size;
}

void push(Q* q, int num)
{
	if (full(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = num;
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

int reverse_pop(Q * q)
{
	if (empty(q))
	{
		return -1;
	}
	int prev = q->front;
	q->front = (q->front - 1 + q->size) % q->size;
	return q->q[prev];
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int num1 = 0, num2 = 0, count = 1, result =0, k =0;
		memset(str, 0, sizeof(str));
		memset(inter, 0, sizeof(inter));
		memset(get, 0, sizeof(get));
		scanf("%s", str);
		int strsize = strlen(str);
		scanf("%d", &num1);
		Q* ary = create(num1);
		scanf("%s", get);
		char* token;
		int number = 0;
		memmove(get, get + 1, strlen(get));
		get[strlen(get) - 1] = 0;
		token = strtok(get, ",");
		while (token != NULL)
		{
			number = atoi(token);
			push(ary, number);
			token = strtok(NULL, ",");
		}
		for (int i = 0; i < strsize; i++)
		{
			if (str[i] == 'R')
			{
				swap(ary);
				count = (count % 2) + 1;
				
			}
			else if (str[i] == 'D')// 1 = 정방향 / 2 = 역방향
			{
				if (count == 1)
				{
					result = pop(ary);
					if (result == -1)
					{
						break;
					}
				}
				else if (count == 2)
				{
					result = reverse_pop(ary);
					if (result == -1)
					{
						break;
					}
				}
			}
		}
		if (result == -1)
		{
			printf("error\n");
		}
		else
		{
			if (count == 1)
			{
				printf("[");
				while (!empty(ary) && ary->rear != (ary->front + 1) % ary->size)
				{
					printf("%d,", pop(ary));
				}
				if (!empty(ary))
				{
					printf("%d", pop(ary));
				}
				printf("]\n");
			}
			else if (count == 2)
			{
				printf("[");
				while (!empty(ary) && ary->rear != (ary->front -1 + ary->size) % ary->size)
				{
					printf("%d,", reverse_pop(ary));
				}
				if (!empty(ary))
				{
					printf("%d", reverse_pop(ary));
				}
				printf("]\n");
			}
		}
		free(ary->q);
		free(ary);
	}
}
