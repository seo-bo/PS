#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	long long num1 = 0;
	scanf("%lld", &num1);
	long long num2 = 0;
	scanf("%lld", &num2);
	long long sum = llabs(num1 - num2);
	printf("%lld", sum);
}