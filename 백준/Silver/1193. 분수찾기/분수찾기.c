#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int row[4] = { 0,1,1,-1 };
	int col[4] = { 1,-1,0,1 };
	int x = 1, y = 1, ud = -1, rl = 0, count = 1, j = 1;
	for (int i = 1; i < num; i++)
	{
		if (j == count)
		{
			j = 0;
			x = x + row[rl];
			y = y + col[rl];
			rl = (rl + 2) % 4;
			ud = (ud + 2) % 4;
			j++, count++;;
		}
		else
		{
			x = x + row[ud];
			y = y + col[ud];
			j++;
		}
	}

	printf("%d/%d", x, y);
}

