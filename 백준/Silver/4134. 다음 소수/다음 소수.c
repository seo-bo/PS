#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		long long get = 0;
		scanf("%lld", &get);
		getchar();
		if (get <= 2)
		{
			printf("%d\n", 2);
		}
		else
		{
			while (1)
			{
				int count = 0;
				for (long long j = 2; j <= sqrt((double)get) + 0.00000001; j++)
				{
					if (get % j == 0)
					{
						count++;
						break;
					}
				}
				if ((count != 0))
				{
					get++;
				}
				else
				{
					printf("%lld\n", get);
					break;
				}
			}
		}
	}
}