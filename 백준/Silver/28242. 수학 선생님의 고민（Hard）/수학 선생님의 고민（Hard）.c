#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Number
{
	long long up;
	long long down;
}Number;

long long gcd(long long num1, long long num2)
{
	long long temp = 0;
	while (num2 != 0)
	{
		temp = num2;
		num2 = num1 % num2;
		num1 = temp;
	}
	return num1;
}

int main(void)
{
	Number x1, x2;
	long long count = 0, num = 0;
	scanf("%lld", &num);
	long long a = num, b = num + 1, c = -(num + 2);
	long long check = (b * b) - (4 * a * c);
	long long check2 = sqrt(check);
	if (check < 0)
	{
		printf("%d", -1);
		return 0;
	}
	if (check2 * check2 != check)
	{
		printf("%d", -1);
		return 0;

	}
	x1.up = -b + check2, x2.up = -b - check2;
	long long get = gcd(x1.up, 2 * a);
	x1.up /= get, x1.down = (2 * a) / get;
	get = gcd(x2.up, 2 * a);
	x2.up /= get, x2.down = (2 * a) / get;
	if (num % (x1.down * x2.down) != 0)
	{
		printf("%d", -1);
		return 0;
	}
	printf("%lld %lld %lld %lld", x1.down, -x1.up, (num / x1.down), -(x2.up * num / x1.down / x2.down));
}