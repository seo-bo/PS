#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int search(int key, int size, int* bry)
{
	int start = 0, end = size - 1;
	while (start <= end)
	{
		int cen = (start + end) / 2;

		if (bry[cen] > key) 
		{ 
			end = cen - 1; 
		}
		else if (bry[cen] < key)
		{
			start = cen + 1;
		}
		else 
			return cen;
	}
}
int delete(int* ary, int size)	
{
	int k = 0;
	for (int i = 1; i < size; i++)
	{
		if (ary[k] == ary[i]) continue;
		{
			ary[++k] = ary[i];
		}
	}

	return ++k;
}
int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 != *(int*)num2)
	{
		return *(int*)num1 - *(int*)num2;
	}
	else
		return 0;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);

	int* ary = (int*)malloc(sizeof(int) * num);
	int* bry = (int*)malloc(sizeof(int) * num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
		bry[i] = ary[i];
	}

	qsort(ary, num, sizeof(int), compare);

	int newsize = delete(ary, num);

	for (int i = 0; i < num; i++)
	{
		int put = search(bry[i], newsize, ary);
		printf("%d ", put);
	}
	
	free(ary);
	free(bry);
	
}
