#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long money = 0;
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int* ary = (int*)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < num; i++)
	{
		while (ary[i] > 0)
		{
			if (i < num - 2)
			{
				if (ary[i + 1] > ary[i + 2])
				{
					while (ary[i + 1] > 0 && ary[i] > 0 && ary[i + 1] != ary[i + 2])
					{
						money += 5;
						ary[i]--;
						ary[i + 1]--;
					}
					while (ary[i + 2] > 0 && ary[i + 1] > 0 && ary[i] > 0)
					{
						money += 7;
						ary[i]--;
						ary[i + 1]--;
						ary[i + 2]--;
					}
					if (ary[i] > 0)
					{
						money += ary[i] * 3;
						ary[i] = 0;
						break;
					}
				}
				else if (ary[i + 1] <= ary[i + 2])
				{
					while (ary[i] > 0 && ary[i + 1] > 0 && ary[i + 2] > 0)
					{
						money += 7;
						ary[i]--;
						ary[i + 1]--;
						ary[i + 2]--;
					}
					while (ary[i] > 0 && ary[i + 1] > 0)
					{
						money += 5;
						ary[i]--;
						ary[i + 1]--;
					}
					if (ary[i] > 0)
					{
						money += ary[i] * 3;
						ary[i] = 0;
						break;
					}
				}
			}
			else if (i < num - 1)
			{
				while (ary[i] > 0 && ary[i + 1] > 0)
				{
					money += 5;
					ary[i]--;
					ary[i + 1]--;
				}
				if (ary[i] > 0)
				{
					money += ary[i] * 3;
					ary[i] = 0;
					break;
				}
			}
			else
			{
				money += ary[i] * 3;
				ary[i] = 0;
				break;
			}
		}
	}
	printf("%lld", money);
}
