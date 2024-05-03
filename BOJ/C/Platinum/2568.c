
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct line
{
	int idx;
	int value;
}line;

int head = -1;

void push(int* stack, int num)
{
	stack[++head] = num;
}
int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int compare(const void* num1, const void* num2)
{
	if (((line*)num1)->value == 0)
	{
		return 1;
	}
	if (((line*)num2)->value == 0)
	{
		return -1;
	}
	return ((line*)num1)->idx - ((line*)num2)->idx;
}

int search(int* stack, int key, int size)
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
	line* ary = (line*)malloc(sizeof(line) * num);
	int* stack = (int*)calloc(num, sizeof(int));
	int* result = (int*)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &ary[i].idx, &ary[i].value);
	}
	qsort(ary, num, sizeof(line), compare);
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			push(stack, ary[i].value);
			result[i] = 0;
		}
		else
		{
			int get = search(stack, ary[i].value, head + 1);
			if (stack[get] < ary[i].value)
			{
				push(stack, ary[i].value);
				result[i] = get + 1;
			}
			else
			{
				stack[get] = ary[i].value;
				result[i] = get;
			}
		}
	}
	free(stack);
	printf("%d\n", num - (head + 1));
	for (int i = num - 1; i >= 0; i--)
	{
		if (head == result[i])
		{
			ary[i].value = 0;
			head--;
		}
	}
	free(result);
	qsort(ary, num, sizeof(line), compare);
	for (int i = 0; i < num; i++)
	{
		if (ary[i].value != 0)
		{
			printf("%d\n", ary[i].idx);
		}
	}
}

