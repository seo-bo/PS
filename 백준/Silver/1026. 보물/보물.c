#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int rcompare(const void* num1, const void* num2)
{
	return *(int*)num2 - *(int*)num1;
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
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &bry[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	qsort(bry, num, sizeof(int), rcompare);
	for (int i = 0; i < num; i++)
	{
		result += (ary[i] * bry[i]);
	}
	printf("%d", result);
	free(ary);
	free(bry);
	
}
