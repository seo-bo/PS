#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007

void modcal(long long num1, long long num2, long long *pos1, long long *pos2)
{
	*pos1 = 1;
	*pos2 = 1;
	long long base = num1;
	long long basem = (num1 - 1 + MOD) % MOD;
	while (num2 > 0)
	{
		if (num2 % 2 == 1)
		{
			*pos1 = (*pos1* base) % MOD;
			*pos2 = (*pos2 * basem) % MOD;
		}
		base = (base * base) % MOD;
		basem = (basem * basem) % MOD;
		num2 /= 2;
	}
	
}

int main(void)
{
	long long num1 = 0, num2 = 0, pos1 = 1, pos2 = 1;
	scanf("%lld %lld", &num2, &num1);
	modcal(num1, num2, &pos1, &pos2);
	long long result = (pos1 - pos2 + MOD) % MOD;
	printf("%lld", result);
}