#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long Min(long long num1, long long num2)
{
	return (num1 > num2) ? num2 : num1;
}

long long search(long long size, long long key)
{
	long long start = 1, end = key, temp = 0;
	while (start <= end)
	{
		long long cen = (start + end) / 2;
		long long get = 0;
		for (int i = 1; i <= size; i++)
		{
			get += Min(cen / i, size);
		}

		if (get >= key)
		{
			temp = cen;
			end = cen - 1;
		}
		else
		{
			start = cen + 1;
		}
	}
	return temp;
}


int main(void)
{
	long long num = 0, key =0;
	scanf("%lld %lld", &num, &key);
	long long result = search(num, key);
	printf("%lld", result);
}
