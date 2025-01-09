#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	int person = 0, count = 0, what = 0, bun = 0, degi = 0, con = 2;
	scanf("%d %d %d", &person, &count, &what);
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
			{
				bun++;
			}
			else
			{
				degi++;
			}
			if (bun == count && what == 0 || degi == count && what == 1)
			{
				printf("%d", (bun + degi - 1) % person);
				return 0;
			}
		}
		for (int i = 0; i < con; i++)
		{
			bun++;
			if (bun == count && what == 0)
			{
				printf("%d", (bun + degi - 1) % person);
				return 0;
			}
		}
		for (int i = 0; i < con; i++)
		{
			degi++;
			if (degi == count && what == 1)
			{
				printf("%d", (bun + degi - 1) % person);
				return 0;
			}
		}
		con++;
	}
}