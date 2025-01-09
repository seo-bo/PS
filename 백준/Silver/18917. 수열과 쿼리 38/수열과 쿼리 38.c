#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	long long sum = 0, xorsum = 0;
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		switch (temp)
		{
			case 1:
			{
				int get = 0;
				scanf("%d", &get);
				sum += get;
				xorsum ^= get;
				break;
			}
			case 2:
			{
				int get = 0;
				scanf("%d", &get);
				sum -= get;
				xorsum ^= get;
				break;
			}
			case 3:
			{
				printf("%lld\n", sum);
				break;
			}
			case 4:
			{
				printf("%lld\n", xorsum);
				break;
			}
		}
	}
}