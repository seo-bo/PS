#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int main(void)
{
	long long num1 = 0, num2 = 0, go = 0, sleep = 0, result1 =0, result2 =0, time1 =0, time2 =0;
	scanf("%lld %lld", &num1, &num2);
	getchar();
	scanf("%lld %lld", &go, &sleep);
	getchar();
	long long a = ((num1 / 8) - 1), b = ((num2 / 8) - 1);
	if (num1 <= 8)
	{
		printf("Zip\n%lld", num1);
		return 0;
	}
	else if (num2 <= 8)
	{
		printf("Dok\n%lld", num2 + go);
		return 0;
	}
	else
	{
		num1 -= a * 8;
		num2 -= b * 8;
		while (1)
		{
			if (num1 <= 8)
			{
				time1 += num1;
				break;
			}
			else
			{
				num1 -= 8;
				time1 += (8 + sleep);
			}
		}
		while (1)
		{
			if (num2 <= 8)
			{
				time2 += num2 + go;
				break;
			}
			else
			{
				num2 -= 8;
				time2 += (8 + sleep + (go*2));
			}
		}
		time1 += (a * (8 + sleep));
		time2 += (b * (8 + sleep + (go * 2)));
	}
	if (time1 > time2)
	{
		printf("Dok\n%lld", time2);
	}
	else
	{
		printf("Zip\n%lld", time1);
	}
}