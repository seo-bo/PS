#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, x=0, y= 0;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	for (int i = -999; i <= 999; i++)
	{
		for (int j = -999; j <= 999; j++)
		{
			if ((a * i + b * j) == c && (d * i + e * j) == f)
			{
				printf("%d %d", i, j);
				return 0;
			}
		}
	}
}
