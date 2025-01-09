#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int head = -1;

void push(int* stack, int num)
{
	stack[++head] = num;
}

int lower_search(int* stack, int key, int size)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (stack[cen] >= key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}


int main(void)
{
	int num = 0, new_head = -1;
	scanf("%d", &num);
	int* stack = (int*)calloc(num, sizeof(int));
	int* ary = (int*)calloc(num, sizeof(int));
	int* result = (int*)calloc(num, sizeof(int));
	int* save = (int*)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			push(stack, ary[i]);
			result[i] = 0;
		}
		else
		{
			int get = lower_search(stack, ary[i], head + 1);
			if (stack[get] < ary[i])
			{
				push(stack, ary[i]);
				result[i] = get + 1;
			}
			else if (stack[get] >= ary[i])
			{
				stack[get] = ary[i];
				result[i] = get;
			}
		}
	}
	printf("%d\n", head + 1);
	for (int i = num - 1; i >= 0; i--)
	{
		if (head == result[i])
		{
			save[++new_head] = ary[i];
			head--;
		}
	}
	for (int i = new_head; i >= 0; i--)
	{
		printf("%d ", save[i]);
	}
	free(stack);
	free(ary);
	free(result);
	free(save);
}