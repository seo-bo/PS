#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Power(long long num1, long long num2, long long num3)
{
	if (num2 == 0)
	{
		return 1;
	}
	long long get = Power(num1, (num2 / 2), num3);
	long long temp = get * get % num3;
	if (num2 % 2 == 0)
	{
		return temp;
	}
	else
	{
		return num1 * temp % num3;
	}
}

int main(void)
{
	long long num1 = 0, num2 = 0, num3 = 0;
	scanf("%lld %lld %lld", &num1, &num2, &num3);
	long long result = Power(num1, num2, num3);
	printf("%lld", result);
}