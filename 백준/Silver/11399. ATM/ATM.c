#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num = 0, result = 0;
	scanf("%d", &num);
	int* ary = (int*)malloc(sizeof(int) * num);
	int* bry = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
		{
			bry[i] = ary[i];
			result += ary[i];
		}
		else
		{
			bry[i] = bry[i - 1] + ary[i];
			result += bry[i];
		}
	}
	printf("%d", result);
	free(ary);
	free(bry);
}
