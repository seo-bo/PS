#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int ary[100] = { 0, };
int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int Min(int num1, int num2)
{
	return (num1 < num2) ? num1 : num2;
}

int gcd(int num1, int num2)
{
	while (1)
	{
		if ((num1 % num2) == 0)
		{
			return num2;
		}
			int temp = (num1 % num2);
			num1 = num2;
			num2 = temp;
	}
}

int search(int num)
{
	int k = 0;
	for (int i = 1; i * i <= num; i++)
	{
		if (num % i == 0)
		{
			ary[k] = i;
			k++;
			if (i != num / i)
			{
				ary[k] = num / i;
				k++;
			}
		}
	}
	return k;
}

int main(void)
{
	int num1 = 0, num2 = 0;
	scanf("%d %d", &num1, &num2);
	int big = Max(num1, num2); int small = Min(num1, num2);
	int result = gcd(big, small); int size = search(result);
	for (int i = 0; i < size; i++)
	{
		printf("%d %d %d\n", ary[i], (num1 / ary[i]), (num2 / ary[i]));
	}
}
