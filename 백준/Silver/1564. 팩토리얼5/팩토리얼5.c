#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define mod 1000000000000

int main(void)
{
	long long num = 0, result = 1;
	scanf("%lld", &num);
	for (int i = 1; i <= num; i++)
	{
		result *= i;
		while (result % 10 == 0)
		{
			result /= 10;
		}
		result %= mod;
	}
	printf("%05lld", result % 100000);
}