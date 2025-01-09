#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MOD 4294967296

bool not_prime[100000001];

void get_prime(int num)
{
	long long result = 1;
	for (long long i = 2; i <= num; ++i)
	{
		if (!not_prime[i])
		{
			long long temp = i;
			while (temp * i <= num)
			{
				temp *= i;
			}
			result = (result * temp) % MOD;
			for (long long j = i * i; j <= num; j += i)
			{
				not_prime[j] = true;
			}
		}
	}
	printf("%lld", result);
	return;
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	get_prime(num);
	return 0;
}