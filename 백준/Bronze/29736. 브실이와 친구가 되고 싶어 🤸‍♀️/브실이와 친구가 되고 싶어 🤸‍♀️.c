#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	int start = 0, end = 0, sol = 0, x = 0, result = 0;
	scanf("%d %d", &start, &end);
	getchar();
	scanf("%d %d", &sol, &x);
	getchar();
	int start2 = sol - x, end2 = sol + x;
	if (start < start2)
	{
		if (end > sol + x)
		{
			result = end2 - start2 + 1;
		}
		else if (end <= sol + x)
		{
			result = end - start2 + 1;
		}
	}
	else
	{
		if (end > sol + x)
		{
			result = end2 - start + 1;
		}
		else if (end <= sol + x)
		{
			result = end - start +1;
		}
	}
	if (result <= 0)
	{
		printf("IMPOSSIBLE");
	}
	else 
	{
		printf("%d", result);
	}
}