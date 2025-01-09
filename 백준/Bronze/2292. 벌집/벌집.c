#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num = 0, go = 5, count = 1, start = 2;
	scanf("%d", &num);
	while (1)
	{
		if (start <= num)
		{
			count++;
			start = start + go + 1;
			go += 6;
		}
		else
			break;
	}
	printf("%d", count);
}

