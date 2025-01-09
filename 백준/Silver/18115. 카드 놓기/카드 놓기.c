#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int rsize = 0;

typedef struct Q
{
	int size, front, rear;
	int* q;
}Q;

Q* create(int size)
{
	Q* new = (Q*)malloc(sizeof(Q));
	new->front = 0;
	new->rear = 0;
	new->size = size + 1;
	new->q = (int*)malloc(sizeof(int) * new->size);
	for (int i = 0; i < new->size; i++)
	{
		new->q[i] = -1;
	}
	return new;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int* test = (int*)malloc(sizeof(int) * num);
	int* card = (int*)malloc(sizeof(int) * num);
	Q* ary = create(num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &test[i]);
		getchar();
		card[i] = num - i;
	}
	for (int i = num - 1; i >= 0; i--)
	{
		switch (test[i])
		{
			case 1:
			{
				if (rsize == 0)
				{
					ary->front = (ary->front - 1 + ary->size) % ary->size;
					ary->rear = ary->front;
					ary->q[ary->front] = card[i];
				}
				else
				{
					ary->front = (ary->front + 1) % ary->size;
					ary->q[ary->front] = card[i];
				}
				rsize++;
				break;
			}
			case 2:
			{
				if (ary->q[(ary->front - 1 + ary->size) % ary->size] == -1)
				{
					ary->q[(ary->front - 1 + ary->size) % ary->size] = card[i];
				}
				else
				{
					int temp = ary->q[ary->front];
					ary->q[ary->front] = card[i];
					ary->front = (ary->front + 1) % ary->size;
					ary->q[ary->front] = temp;
				}
				if (rsize == 1)
				{
					ary->rear = (ary->front - 1 + ary->size) % ary->size;
				}
				rsize++;
				break;
			}
			case 3:
			{
				ary->rear = (ary->rear - 1 + ary->size) % ary->size;
				ary->q[ary->rear] = card[i];
				rsize++;
				break;
			}
		}
	}
	for (int i = ary->front; i != (ary->rear - 1 + ary->size) % ary->size; i = (i - 1 + ary->size) % ary->size)
	{
		printf("%d ", ary->q[i]);
	}
	free(ary->q);
	free(ary);
	free(card);
	free(test);
}