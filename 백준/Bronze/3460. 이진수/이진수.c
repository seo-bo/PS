#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int ary[20];
int main(void)
{
	int count = 0;
	scanf("%d", &count);
	while (1)
	{
		if (count == 0)
		{
			break;
		}
		memset(ary, 0, sizeof(ary));
		 int num = 0, i = 0, clk = 0;
		scanf("%d", &num);
		while (1)
		{
			if (num == 0)
			{
				break;
			}
			ary[i] = num % 2;
			num = num / 2;
			i++;
			clk++;
		}
		for (int i = 0; i < clk; i++)
		{
			if (ary[i] == 1)
			{
				printf("%d ", i);
			}
		}
		printf("\n");
		count--;
	}
}

