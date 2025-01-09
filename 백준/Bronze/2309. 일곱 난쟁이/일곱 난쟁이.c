#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
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
	int ary[9] = { 0, };
	int all = 0;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &ary[i]);
		all += ary[i];
	}
	all = all - 100;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 1 + i; j < 9; j++)
		{
			if (all == (ary[i] + ary[j]))
			{
				ary[i] = 0;
				ary[j] = 0;
				break;
			}
		}
		if (ary[i] == 0)
		{
			break;
		}
	}
	qsort(ary, 9, sizeof(int), compare);
	for (int i = 0; i < 9; i++)
	{
		if (ary[i] != 0)
		{
			printf("%d\n", ary[i]);
		}
	}
}

