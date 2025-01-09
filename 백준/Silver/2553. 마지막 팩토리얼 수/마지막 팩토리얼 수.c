#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

long long ary[20001] = { 0, };

int facto(int num)
{
	ary[0] = 1, ary[1] = 1;
	for (long long i = 2; i <= num; i++)
	{
		ary[i] = (i * ary[i - 1]) % 10000000;
		while (ary[i] % 10 == 0 && ary[i] != 0)
		{
			ary[i] /= 10;
		}
	}
	return ary[num];
}

int main()
{
	
	int num = 0;
	scanf("%d", &num);
	int result = facto(num);
	printf("%d", result % 10);
}
