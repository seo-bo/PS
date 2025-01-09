#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int search(int*ary, int key, int size)
{
	int start = 0;
	int end = size - 1;
	while(1)
	{
		int cen = ((start + end) / 2);
		if (key == ary[cen] || key == ary[start] || key == ary[end])
		{
			return 1;
		}
		else if (key < ary[cen])
		{
			end = cen - 1;
		}
		else if (key > ary[cen])
		{
			start = cen + 1;
		}
		if (end <= start)
		{
			return 0;
		}
	}
}
int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 > *(int*)num2)
	{
		return 1;
	}
	if (*(int*)num1 < *(int*)num2)
	{
		return -1;
	}
	else
		return 0;
}
int main(void)
{
	int num1 = 0, num2 = 0;
	scanf("%d", &num1);

	int* ary = (int*)malloc(sizeof(int) * num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &ary[i]);
	}
	scanf("%d", &num2);
	int* bry = (int*)malloc(sizeof(int) * num2);
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &bry[i]);
	}
	qsort(ary, num1, sizeof(int), compare);
	for (int i = 0; i < num2; i++)
	{
		int result = search(ary, bry[i], num1);
		printf("%d\n", result);
	}
	
	free(ary);
}
