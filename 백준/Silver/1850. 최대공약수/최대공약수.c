#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long Max(long long num1, long long num2)
{
	return (num1 > num2) ? num1 : num2;
}

long long Min(long long num1, long long num2)
{
	return (num1 > num2) ? num2 : num1;
}

long long gcd(long long num1, long long num2)
{
	long long temp = num1 % num2;
	while (temp > 0)
	{
		num1 = num2;
		num2 = temp;
		temp = num1 % num2;

	}
	return num2;
}

int main(void)
{
	long long num1 = 0, num2 = 0;
	scanf("%lld %lld", &num1, &num2);
	long long result = gcd(Max(num1, num2), Min(num1, num2));
	for (long long i = 0; i < result; i++)
	{
		printf("1");
	}
}