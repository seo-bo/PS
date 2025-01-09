#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int dot = 2;
	for (int i = 0; i < num; i++)
	{
		dot = 2 * dot - 1;
	}
	int dotp = dot * dot;
	printf("%d", dotp);
}

