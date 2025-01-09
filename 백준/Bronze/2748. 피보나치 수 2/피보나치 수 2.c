#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

long long Fibo[91] = { 0, };

long long getfibo(int num)
{
	if (num == 0 || num == 1)
	{
		return Fibo[num];
	}
	else if (Fibo[num] != 0)
	{
		return Fibo[num];
	}
	else
	{
		Fibo[num] = getfibo(num - 1) + getfibo(num - 2);
		return Fibo[num];
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Fibo[0] = 0, Fibo[1] = 1;
	long long result = getfibo(num);
	printf("%lld", result);
}


