#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	while (1)
	{
		int num = 0;
		int sum = 0;
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		for (int i = 1; i <= num; i++)
		{
			sum += i;
		}
		printf("%d\n", sum);
	}
}