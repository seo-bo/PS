#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[246913];
int get(int* ary, int num)
{
	int prime_count = 0;
	for (int i = 2; i * i <= 2 * num; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 2 * num; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	for (int i = num+1; i <= 2 * num; i++)
	{
		if (ary[i] == 0)
		{
			prime_count++;
		}
	}
	return prime_count;
}

int main(void)
{
	int num = 0;
	ary[0] = 1, ary[1] = 1;
	memset(ary, 0, sizeof(ary));
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			return 0;
		}
		int prime = get(ary, num);
		printf("%d\n", prime);
	}
}