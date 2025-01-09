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
	int num = 0;
	scanf("%d", &num);
	int* stack = (int*)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		if (i == 0)
		{
			push(stack, temp);
		}
		else
		{
			int get = lower_search(stack, temp, head + 1);
			if (stack[get] < temp)
			{
				push(stack, temp);
			}
			else
			{
				stack[get] = temp;
			}
		}
	}
	free(stack);
	printf("%d", head + 1);
}