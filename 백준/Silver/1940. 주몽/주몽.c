#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num = 0, fin = 0, j = 0, count = 0;
	scanf("%d", &num);
	scanf("%d", &fin);
	int* ary = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	int start = 0, end = num - 1;
	while (1)
	{
		if (start >= end)
		{
			break;
		}
		int sum = ary[start] + ary[end];
		if (sum == fin)
		{
			count++;
			start++;
			end--;
		}
		else if (sum < fin)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	printf("%d", count);
	free(ary);
}