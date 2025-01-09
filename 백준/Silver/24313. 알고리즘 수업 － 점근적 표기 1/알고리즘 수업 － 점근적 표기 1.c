#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a1 = 0, a0 = 0, c = 0, n0 = 0;
	scanf("%d %d %d %d", &a1, &a0, &c, &n0);

	if ((c - a1) < 0 || (c - a1) * n0 < a0)
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", 1);
	}
}