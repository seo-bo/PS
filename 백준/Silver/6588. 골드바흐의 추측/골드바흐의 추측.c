#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ary[1000001] = { 0, };

void Prime(int num)
{
	ary[0] = 1;
	ary[1] = 1;
	for (int i = 2; i * i <= num; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= num; j += i)
			{
				ary[j] = 1;
			}
		}
	}
}


int main(void)
{
	Prime(1000000);
	while (1)
	{
		int num = 0;
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		else
		{
			int temp = num / 2;
			for (int i = 2; i <= temp; i++)
			{
				if (ary[i] == 0)
				{
					if (ary[num - i] == 0)
					{
						printf("%d = %d + %d\n", num, i, num - i);
						break;
					}
				}
			}
		}
	}
}