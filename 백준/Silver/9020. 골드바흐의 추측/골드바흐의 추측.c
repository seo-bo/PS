#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int ary[10001] = { 0, };

void prime()
{
	ary[0] = ary[1] = 1;
	for (int i = 2; i * i <= 10000; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 10000; j += i)
			{
				ary[j] = 1;
			}
		}
	}
}

int main(void)
{
	prime();
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int get = 0;
		scanf("%d", &get);
		int temp = get / 2;
		for (int j = temp; j > 0; j--)
		{
			if (ary[j] == 0)
			{
				if (ary[get - j] == 0)
				{
					printf("%d %d\n", j, get - j);
					break;
				}
			}
		}
	}
}