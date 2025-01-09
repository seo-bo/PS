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

int main(void)
{
	int num = 0, count = 0, command = 0, now = 0;
	scanf("%d", &num);
	Q* ary = create(num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary->q[i]);
	}
	while (count < num)
	{
		printf("%d ", now + 1);
		command = ary->q[now];
		ary->q[now] = 0;
		count++;

		if (count == num)
		{
			break;
		}

		if (command > 0)
		{
			while (command > 0)
			{
				now = (now + 1) % num;
				if (ary->q[now] != 0)
				{
					command--;
				}
			}
		}
		else
		{
			while (command < 0)
			{
				now = (now - 1 + num) % num;
				if (ary->q[now] != 0)
				{
					command++;
				}
			}
		}
	}
	free(ary->q);
	free(ary);
}
