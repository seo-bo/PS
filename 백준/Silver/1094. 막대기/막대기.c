#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x = 0, len = 64, count = 0;
	scanf("%d", &x);
	while (1)
	{
		if (x == 0)
		{
			break;
		}
		if (len > x)
		{
			len /= 2;
		}
		else if (len <= x)
		{
			x = x - len;
			len /= 2;
			count++;
		}
	}
	printf("%d", count);
}