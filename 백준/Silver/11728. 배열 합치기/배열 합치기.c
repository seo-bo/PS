#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int compare(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

int main(void)
{
	int num1 = 0, num2 = 0;
	scanf("%d %d", &num1, &num2);
	int size = num1 + num2;
	int* ary = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, size, sizeof(int), compare);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", ary[i]);
	}
	free(ary);
}