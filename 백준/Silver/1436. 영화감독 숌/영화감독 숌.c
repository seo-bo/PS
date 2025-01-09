#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0, doom = 0, i = 1, cur =1;
	scanf("%d", &num);
	if (num == 1)
	{
		printf("%d", 666);
		return 0;
	}
	while (1)
	{
		doom = i + 666;
		int count = 0;
		while (1)
		{
			if (doom == 0)
			{
				break;
			}
			if (doom % 1000 == 666)
			{
				count++;
				break;
			}
			doom /= 10;
		}
		if (count != 0)
		{
			cur++;
			if (cur == num)
			{
				printf("%d", i+666);
				return 0;
			}
		}
		i++;
	}
}