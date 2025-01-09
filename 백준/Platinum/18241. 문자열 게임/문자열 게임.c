#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char stack[300005];
char reverse_stack[300005];
char bomb[15];
char reverse_bomb[15];
int head = -1;
int reverse_head = -1;

typedef struct Q
{
	int size, front, rear;
	char* q;
}Q;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = new->rear = 0;
	new->size = size + 1;
	new->q = (char*)malloc(sizeof(char) * (new->size + 1));
	return new;
}

int empty(Q* q)
{
	return q->front == q->rear;
}

void insert(Q* q, char num)
{
	q->rear = (q->rear + 1) % q->size;
	q->q[q->rear] = num;
}

char front_pop(Q* q)
{
	if (empty(q))
	{
		return;
	}
	q->front = (q->front + 1) % q->size;
	return q->q[q->front];
}

char rear_pop(Q* q)
{
	if (empty(q))
	{
		return;
	}
	int prev = q->rear;
	q->rear = (q->rear - 1 + q->size) % q->size;
	return q->q[prev];
}

int main(void)
{
	int result = 0;
	Q* q = create(300010);
	scanf("%s", bomb);
	getchar();
	scanf("%s", stack);
	getchar();
	int len = strlen(stack);
	for (int i = 0; i < len; i++)
	{
		insert(q, stack[i]);
	}
	len = strlen(bomb);
	int k = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		reverse_bomb[k] = bomb[i];
		k++;
	}
	int test = 0;
	scanf("%d", &test);
	getchar();
	memset(stack, 0, sizeof(stack));
	for (int i = 0; i < test; i++)
	{
		char get;
		scanf(" %c", &get);
		getchar();
		if (get == 'L')
		{
			while (!empty(q))
			{
				stack[++head] = front_pop(q);
				if (head >= len - 1 && !memcmp(stack + head - len + 1, bomb, len))
				{
					head -= len;
					result++;
					break;
				}
			}
		}
		else if (get == 'R')
		{
			while (!empty(q))
			{
				reverse_stack[++reverse_head] = rear_pop(q);
				if (reverse_head >= len - 1 && !memcmp(reverse_stack + reverse_head - len + 1, reverse_bomb, len))
				{
					reverse_head -= len;
					result++;
					break;
				}
			}
		}
		if (empty(q))
		{
			while (head > -1)
			{
				reverse_stack[++reverse_head] = stack[head--];
				if (reverse_head >= len - 1 && memcmp(reverse_stack + reverse_head - len + 1, reverse_bomb, len) == 0)
				{
					reverse_head -= len;
					result++;
					break;
				}
			}
		}
	}
	while (!empty(q))
	{
		reverse_stack[++reverse_head] = rear_pop(q);
	}
	while (head > -1)
	{
		reverse_stack[++reverse_head] = stack[head--];
	}
	reverse_stack[++reverse_head] = '\0';
	printf("%d\n", result);
	for (int i = reverse_head - 1; i >= 0; i--)
	{
		printf("%c", reverse_stack[i]);
	}
	printf("\n");
	if (strstr(reverse_stack, reverse_bomb) == NULL)
	{
		printf("Perfect!");
	}
	else
	{
		printf("You Lose!");
	}
}