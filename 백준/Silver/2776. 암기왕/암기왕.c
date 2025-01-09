#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int search(int* ary, int key, int size)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		int cen = (start + end) / 2;
		if (ary[cen] == key)
		{
			return cen;
		}
		else if (ary[cen] > key)
		{
			end = cen - 1;
		}
		else if (ary[cen] < key)
		{
			start = cen + 1;
		}
	}
	return -1;
}

int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 > *(int*)num2)
	{
		return 1;
	}
	else if (*(int*)num1 < *(int*)num2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int num1 = 0, num2 = 0;
		scanf("%d", &num1);
		int* ary = (int*)malloc(sizeof(int) * num1);
		for (int i = 0; i < num1; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, num1, sizeof(int), compare);
		scanf("%d", &num2);
		int* bry = (int*)malloc(sizeof(int) * num2);
		for (int i = 0; i < num2; i++)
		{
			scanf("%d", &bry[i]);
		}
		for (int i = 0; i < num2; i++)
		{
			if (search(ary, bry[i], num1) != -1)
			{
				printf("%d\n", 1);
			}
			else
			{
				printf("%d\n", 0);
			}
		}
		free(ary);
		free(bry);
	}
}