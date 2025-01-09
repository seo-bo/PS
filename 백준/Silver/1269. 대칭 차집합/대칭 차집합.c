#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

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


int main(void) 
{
	int num1 = 0, num2 = 0, result = 0;
	scanf("%d %d", &num1, &num2);
	int* ary = malloc(sizeof(int) * num1);
	int* bry = malloc(sizeof(int) * num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &bry[i]);
	}
	qsort(ary, num1, sizeof(int), compare);
	qsort(bry, num2, sizeof(int), compare);
	for (int i =0; i< num2; i++)
	{
		if (search(ary, bry[i], num1) == -1)
		{
			result++;
		}
	}
	for (int i = 0; i < num1; i++)
	{
		if (search(bry, ary[i], num2) == -1)
		{
			result++;
		}
	}
	printf("%d", result);
	free(ary);
	free(bry);
}
