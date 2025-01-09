#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int num1, int num2)
{
	while (num2)
	{
		int i = num2;
		num2 = num1 % num2;
		num1 = i;
	}
	return num1;
}
int main(void)
{
	int deno1 = 0, nume1 = 0, deno2 = 0, nume2 = 0;
	scanf("%d %d %d %d", &deno1, &nume1, &deno2, &nume2);
	int deno = (deno1 * nume2) + (deno2 * nume1);
	int nume = nume1 * nume2;
	int get = gcd(deno, nume);
	printf("%d %d", (deno / get), (nume / get));
}
