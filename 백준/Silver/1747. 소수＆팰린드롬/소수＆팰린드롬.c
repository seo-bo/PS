#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int ary[1003002] = { 0, };
char save[10];

void prime()
{
	ary[0] = 1, ary[1] = 1;
	for (int i = 2; i * i <= 1003001; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i * i; j <= 1003001; j += i)
			{
				ary[j] = 1;
			}
		}
	}
}

int palin(int temp)
{
	memset(save, 0, sizeof(save));
	sprintf(save, "%d", temp);
	int size = strlen(save);
	int start = 0, end = size - 1;
	while (start <= end)
	{
		if (save[start] != save[end])
		{
			return -1;
		}
		start++;
		end--;
	}
	return 1;
}

int main(void)
{
	prime();
	int num = 0;
	scanf("%d", &num);
	if (num == 1000000)
	{
		printf("%d", 1003001);
		return 0;
	}
	else
	{
		int temp = num;
		while (1)
		{
			if (ary[num] == 0)
			{
				int result = palin(num);
				if (result == 1)
				{
					printf("%d", num);
					return 0;
				}
				else
				{
					num++;
				}
			}
			else
			{
				num++;
			}
		}
	}
}