#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int ary[7500001] = { 0, };

void prime()
{
	ary[0] = 1, ary[1] = 1;
	for (int i = 2; i * i <= 7500001; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 7500001; j += i)
			{
				ary[j] = 1;
			}
		}
	}
}

int main(void)
{
	prime();
	int count = 1, num = 0;
	scanf("%d", &num);
	for (int i = 2; i <= 7500002; i++)
	{
		if (ary[i] == 0)
		{
			if (count == num)
			{
				printf("%d", i);
				return 0;
			}
			else
			{
				count++;
			}
		}
	}
}