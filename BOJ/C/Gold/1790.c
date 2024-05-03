#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char number[11] = { 0, };
int main(void)
{
	long long num = 0, count = 0, quo = 0, rem = 0;
	scanf("%lld %lld", &num, &count);
	for (int i = 1; i <= 9; i++)
	{
		if (count > 9 * i * pow(10, i - 1))
		{
			count -= 9 * i * pow(10, i - 1);
		}
		else if (count <= 9 * i * pow(10, i - 1))
		{
			quo = (long long)ceil(((double)count / (double)i)) + pow(10, i - 1) - 1; 
			if (quo > num)
			{
				printf("%d", -1);
				return 0;
			}
			rem = count % i;
			sprintf(number,"%lld", quo);
			break;
		}
	}
	int size = strlen(number);

	if (rem == 0)
	{
			printf("%d", number[size - 1] - '0');
	}
	else
			printf("%d", number[rem - 1] - '0');
		
}
