#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 != *(int*)num2)
	{
		return (*(int*)num2 - *(int*)num1);
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	int num = 0, get = 0;
	scanf("%d %d", &num, &get);
	int* ary = malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	printf("%d", ary[get - 1]);
	free(ary);
}
