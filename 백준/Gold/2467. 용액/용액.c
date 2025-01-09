#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int* ary = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	int start = 0, end = num - 1, sum = abs(ary[start] + ary[end]);
	int init = ary[start], fin = ary[end];
	while (start < end)
	{
		int get = ary[start] + ary[end];
		if (abs(get) < sum)
		{
			sum = abs(get);
			init = ary[start];
			fin = ary[end];
		}
		if (get < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	free(ary);
	printf("%d %d", init, fin);
}