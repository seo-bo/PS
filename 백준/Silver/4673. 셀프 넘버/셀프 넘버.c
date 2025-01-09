#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[10001] = { 0, };
int main(void)
{
	for (int i = 0; i < 10000; i++)
	{
		ary[i] = i;
	}
	for (int i = 1; i < 10000; i++)
	{
		int result = 0, k = 0;
		while (1)
		{
			if (i / (int)pow(10, k) == 0)
			{
				break;
			}
			else
			{
				result += (i % (int)pow(10, k + 1)) / (int)pow(10, k);
				k++;
			}
		}
		if (i + result < 10000)
		{
			ary[i + result] = 0;
		}
	}
	for (int i = 0; i < 10000; i++)
	{
		if (ary[i] != 0)
		{
			printf("%d\n",ary[i]);
		}
	}
}