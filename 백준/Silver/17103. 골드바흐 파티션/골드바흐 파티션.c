#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1000001] = { 0, };

int prime(void)
{
	for (int i = 2; i <= 1000000; i++)
	{
		ary[i] = i;
	}
	for (int i = 2; i * i <= 1000000; i++)
	{
		if (ary[i] != 0)
		{
			for (int j = i * i; j <= 1000000; j += i)
			{
				ary[j] = 0;
			}
		}
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	prime();
	for (int i = 0; i < num; i++)
	{
		int get = 0, result =0;
		scanf("%d", &get);
		getchar();
		for (int j = 2; j < get; j++)
		{
			if ((ary[get - j] + ary[j]) == get)
			{
				result++;
				if (get - j == j)
				{
					result++;
				}
			}
		}
		printf("%d\n",(result/2));
	}
}