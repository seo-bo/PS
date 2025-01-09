#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	int size = 0, add = 0, pop = 0, cur = 0;
	scanf("%d %d %d", &size, &add, &pop);
	getchar();
	for (int i = 0; i < add + pop; i++)
	{
		int inst = 0;
		scanf("%d", &inst);
		getchar();
		if (inst == 1)
		{
			if (size > cur)
			{
				cur++;
			}
			else
			{
				cur++;
				size *= 2;
			}
		}
		else if (inst == 0)
		{
			cur--;
		}
	}
	printf("%d", size);
}