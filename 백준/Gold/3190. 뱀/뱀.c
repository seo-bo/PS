#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct
{
	int x, y;
}position;

typedef struct
{
	int go;
	char rot;
}Turn;

typedef struct
{
	int head, tail, size;
	position* q;
}Q;

Q* create(int size)
{
	Q* new = malloc(sizeof(Q));
	new->head = 0;
	new->tail = 0;
	new->size = size + 3;
	new->q = malloc(sizeof(position) * (size + 3));
	return new;
}

int empty(Q*q)
{
	return q->head == q->tail;
}

int full(Q* q)
{
	return q->head == (q->tail + 1) % q->size;
}

void push(Q* q, position num)
{
	if (full(q))
	{
		return;
	}
	q->tail = (q->tail + 1) % q->size;
	q->q[q->tail] = num;
}

position pop(Q* q)
{
	if (empty(q))
	{
		position pos = { -1, -1 };
		return pos;
	}
	q->head = (q->head + 1) % q->size;
	return q->q[q->head];
}

int move(Q* q, position next, int** ary)
{
	push(q, next);
	if (ary[next.y][next.x] == -1)
	{
		return -1;
	}
	else if (ary[next.y][next.x] != 1)
	{
		position tail = pop(q);
		ary[tail.y][tail.x] = 0;
	}
	ary[next.y][next.x] = -1;
	return 0;
}

int main(void)
{
	int num = 0, test1 = 0, test2 = 0, dir = 1, time = 0, z = 0, result = 0;
	scanf("%d", &num);
	int** ary = (int**)malloc(sizeof(int*) * (num + 2));
	for (int i = 0; i < num + 2; i++)
	{
		ary[i] = malloc(sizeof(int) * (num + 2));
	}
	for (int i = 0; i <= num + 1; i++)
	{
		for (int j = 0; j <= num + 1; j++)
		{
			if (i == 0 || j == 0 || i == (num + 1) || j == (num + 1))
			{
				ary[i][j] = -1;
			}
			else
			{
				ary[i][j] = 0;
			}
		}
	}
	scanf("%d", &test1);
	for (int i = 0; i < test1; i++)
	{
		int applex, appley = 0;
		scanf("%d %d", &appley, &applex);
		getchar();
		ary[appley][applex] = 1;
	}
	scanf("%d", &test2);
	Turn* turn = (Turn*)malloc(sizeof(Turn) * test2);
	for (int i = 0; i < test2; i++)
	{
		scanf("%d %c", &turn[i].go, &turn[i].rot);
		getchar();
	}
	Q* q = create(test1);
	position space;
	space.x = 1, space.y = 1;
	push(q, space);
	ary[space.x][space.y] = -1;
	while (result != -1)
	{
		time++;
		if (z <= test2)
		{
			if (turn[z].go < time)
			{
				if (turn[z].rot == 'D')
				{
					dir = (dir % 4) + 1;
				}
				else if (turn[z].rot == 'L')
				{
					dir = (dir + 2) % 4 + 1;
				}
				z++;
			}
		}
		if (dir == 1)
		{
			space.x++;
		}
		else if (dir == 2)
		{
			space.y++;
		}
		else if (dir == 3)
		{
			space.x--;
		}
		else if (dir == 4)
		{
			space.y--;
		}
		result = move(q, space, ary);
	}
	
	for (int i = 0; i < num + 2; i++)
	{
		free(ary[i]);
	}
	free(ary);	
	free(q->q);
	free(q);
	free(turn);
	printf("%d", time);
}