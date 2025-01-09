#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int all = 0, result = 0, i = 1;
	scanf("%d", &all);
	while (1)
	{
		if ((all - i) < 0)
		{
			break;
		}
		else
		{
			all -= i;
			result++;
			i++;
		}
	}
	if (result % 2 == 0)
	{
		printf("%d", i - all);
	}
	else
	{
		printf("%d", 0);
	}
}