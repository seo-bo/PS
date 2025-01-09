#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int temp = i;
		int sum = temp;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (num == sum)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("%d", 0);
}