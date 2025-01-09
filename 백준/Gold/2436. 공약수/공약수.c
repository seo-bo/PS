#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int num1, int num2)
{
	int temp = 1;
	while (temp)
	{
		temp = num1 % num2;
		num1 = num2;
		num2 = temp;
	}
	return num1;
}

int main(void)
{
	int num1 = 0, num2 = 0, result1 = 0, result2 = 0;
	scanf("%d %d", &num1, &num2);
	num2 /= num1;
	for (int i = 1; i * i <= num2; i++)
	{
		if (num2 % i == 0 && gcd(i, num2 / i) == 1)
		{
			result1 = i;
			result2 = num2 / i;
		}
	}
	printf("%d %d", result1 * num1, result2 * num1);
}