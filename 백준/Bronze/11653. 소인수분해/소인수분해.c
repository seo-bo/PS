#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	while (1)
	{
		if (num == 1)
		{
			break;
		}
		else
		{
			for (int j = 2; j <= num; j++)
				if (num % j == 0)
				{
					printf("%d\n", j);
					num = num / j;
					break;
				}
		}
	}
}