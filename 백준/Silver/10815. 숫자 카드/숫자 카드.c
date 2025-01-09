#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare(const void* num1, const void* num2)
{
	return (*(int*)num1 - *(int*)num2);
}
int search(int key, int size, int* ary)
{
	int start = 0, end = size - 1;
	while (1)
	{
		int cen = (start + end) / 2;
		if (key == ary[cen] || key == ary[start] || key == ary[end])
		{
			return 1;
		}
		if (key < ary[cen] )
		{ 
			end = cen - 1; 
		}
		else if (key > ary[cen])
		{
			start = cen + 1;
		}
		if (start >= end)
		{
			return 0;
		}
	}
}

int main(void)
{
	int num_a = 0;
	scanf("%d", &num_a);
	int* ary = (int*)malloc(sizeof(int) * num_a);
	for (int i = 0; i < num_a; i++)
	{
		scanf("%d", &ary[i]);
	}

	int num_b = 0;
	scanf("%d", &num_b);

	int* bry = (int*)malloc(sizeof(int) * num_b);
	for (int i = 0; i < num_b; i++)
	{
		scanf("%d", &bry[i]);
	}

	qsort(ary, num_a, sizeof(int), compare);

	for (int i = 0; i < num_b; i++)
	{
		int result = search(bry[i], num_a, ary);
			printf("%d ", result);
	}

	free(ary);
	free(bry);
}
