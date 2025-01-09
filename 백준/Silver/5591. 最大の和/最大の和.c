#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

long long Max(long long num1, long long num2)
{
	return (num1 > num2) ? num1 : num2;
}


int main(void)
{
	int num = 0, get = 0;
	long long max = 0;
	scanf("%d %d", &num, &get);
	long long* ary = (long long*)malloc(sizeof(long long) * (num + 1));
	long long* prefix = (long long*)malloc(sizeof(long long) * (num + 1));
	ary[0] = prefix[0] = 0;
	for (int i = 1; i <= num; i++)
	{
		scanf("%lld", &ary[i]);
		prefix[i] = prefix[i - 1] + ary[i];
		if (i >= get)
		{
			max = Max(prefix[i] - prefix[i - get], max);
		}
	}
	free(ary);
	free(prefix);
	printf("%lld", max);
}
	
