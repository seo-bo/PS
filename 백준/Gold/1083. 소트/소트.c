#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void sort(int* ary, int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		int Max = i;
		for (int j = i; j <= i + num && j < size; j++)
		{
			if (ary[Max] < ary[j])
			{
				Max = j;
			}
		}
		for (int j = Max; j > i; j--)
		{
			swap(&ary[j], &ary[j - 1]);
		}
		num -= (Max - i);
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	int* ary = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
		getchar();
	}
	int num2 = 0;
	scanf("%d", &num2);
	sort(ary, num, num2);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", ary[i]);
	}
	free(ary);
}
