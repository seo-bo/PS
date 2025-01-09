#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[5] = { 0, };
int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 != *(int*)num2)
	{
		return (*(int*)num1 - *(int*)num2);
	}
	else
	{
		return 0;
	}
}
int main(void)
{
	int avg = 0, cen = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &ary[i]);
		avg += ary[i];
	}
	qsort(ary, 5, sizeof(int), compare);
	printf("%d\n", (avg / 5));
	printf("%d", ary[2]);
}
