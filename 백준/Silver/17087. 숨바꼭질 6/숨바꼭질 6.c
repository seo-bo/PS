#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int ary[100001] = { 0, };
int bry[100001] = { 0, };

int gcd(int num1, int num2)
{
	int result = 0;
	while (1)
	{
		int temp = num1 % num2;
		if (temp == 0)
		{
			break;
		}
		num1 = num2;
		num2 = temp;
	}
	return num2;
}

int compare(const void* num1, const void* num2)
{
	return *(int*)num2 - *(int*)num1;
}

int main(void)
{
	int num = 0, now = 0;
	scanf("%d %d", &num, &now);
	ary[0] = now;
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
		bry[i - 1] = abs(ary[i - 1] - ary[i]);
	}
	if (num == 1)
	{
		printf("%d", abs(ary[0] - ary[1]));
		return 0;
	}
		qsort(bry, num, sizeof(int), compare);
		int result = gcd(bry[0], bry[1]);
		for (int i = 2; i <= num; i++)
		{
			if ((bry[i] % result) != 0)
			{
				if (result > bry[i])
				{
					result = gcd(result, bry[i]);
				}
				else
				{
					result = gcd(bry[i], result);
				}
				if (result == 1)
				{
					printf("%d", 1);
					return 0;
				}
			}
		}
		printf("%d", result);
}