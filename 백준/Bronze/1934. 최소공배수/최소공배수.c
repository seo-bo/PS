#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1: num2;
}

int Min(int num1, int num2)
{
	return (num1 > num2) ? num2 : num1;
}

int gcd(int big, int small)
{
	int temp = 0;
	while (small != 0)
	{
		temp = big % small;
		big = small;
		small = temp;
	}
	return big;
}

int main(void) 
{
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		int result = gcd(Max(num1, num2), Min(num1, num2));
		printf("%d\n", (num1 * num2) / result);
	}
}
