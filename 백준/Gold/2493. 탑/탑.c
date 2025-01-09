#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Top
{
	int number;
	int idx;
}Top;

Top stack[500002];
int head = -1;

void push(Top num)
{
	stack[++head] = num;
}

Top pop()
{
	return stack[head--];
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	Top* ary = (Top*)malloc(sizeof(Top) * (num + 1));
	int* result = (int*)malloc(sizeof(int) * (num + 1));
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i].number);
		ary[i].idx = i;
	}
	result[1] = 0;
	push(ary[1]);
	for (int i = 2; i <= num; i++)
	{
		if (ary[i].number >= stack[head].number)
		{
			while (head > -1 && ary[i].number >= stack[head].number)
			{
				pop();
			}
			if (head == -1)
			{
				result[i] = 0;
			}
			else
			{
				result[i] = stack[head].idx;
			}
			push(ary[i]);
		}
		else
		{
			result[i] = stack[head].idx;
			push(ary[i]);
		}
	}
	for (int i = 1; i <= num; i++)
	{
		printf("%d ", result[i]);
	}
}