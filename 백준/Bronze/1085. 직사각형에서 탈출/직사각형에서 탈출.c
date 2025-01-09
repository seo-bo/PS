#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int x = 0, y = 0, w = 0, h = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int result = x;
	if (result > y)
	{
		result = y;
	}
	if (result > w - x)
	{
		result = w - x;
	}
	if (result > h - y)
	{
		result = h - y;
	}
	printf("%d", result);
}