#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

int count[51] = { 0, };

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int num = 0, result = -1;
	scanf("%d", &num);
	int* ary = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	for (int i = 0; i < num; i++)
	{
		count[ary[i]]++;
	}
	for (int i = 0; i < 51; i++)
	{
		if (count[i] == i)
		{
			int temp = i;
			result = Max(result, temp);
		}
	}
	printf("%d", result);
}