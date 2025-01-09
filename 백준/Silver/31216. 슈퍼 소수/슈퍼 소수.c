#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[318138] = { 0, };
int result[3001] = { 0, };
void prime()
{
	ary[0] = 1, ary[1] = 1;
	for (int i = 2; i * i <= 318137; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 318137; j += i)
			{
				ary[j] = 1;
			}
		}
	}
	int k = 0, count = 1;
	for (int i = 0; i <= 318137; i++)
	{
		if (ary[i] == 0)
		{
			k++;
			if (ary[k] == 0)
			{
				result[count] = i;
				count++;
			}
		}
	}
}

int main(void)
{
	prime();
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int get = 0;
		scanf("%d", &get);
		printf("%d\n", result[get]);
	}
}