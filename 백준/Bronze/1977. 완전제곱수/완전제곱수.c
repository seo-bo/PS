#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char number[10001];

int main(void)
{
	int start = 0, end = 0, low = 0, result=0, count = 0;
	scanf("%d", &start);
	scanf("%d", &end);
	for (int i = 1; i * i <= end; i++)
	{
		if ((i * i) >= start && (i * i) <= end)
		{
			result += (i * i);
			count++;
			if (count == 1)
			{
				low = (i * i);
			}
		}
	}
	if (count == 0)
	{
		printf("%d", -1);
	}
	else
	{
		printf("%d\n", result);
		printf("%d", low);
	}
}


