#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int ary[1000000];
int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 > *(int*)num2)
	{
		return -1;
	}
	if (*(int*)num1 < *(int*)num2)
	{
		return 1;
	}
	else
		return 0;
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	qsort(ary, num, sizeof(int), compare);
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", ary[i]);
	}
	
}
