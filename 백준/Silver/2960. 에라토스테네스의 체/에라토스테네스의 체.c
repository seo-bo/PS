#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int ary[1001] = { 0, };

int prime(int num, int num2)
{ 
	int count = 0;
	for (int i = 2; i <= num; i++)
	{
		if (ary[i] == 0)
		{
			for (int j = i; j <= num; j += i)
			{
				if (ary[j] == 0)
				{
					ary[j] = 1;
					count++;
				}
				if (count == num2)
				{
					return j;
				}
			}
		}
	}
}

int main(void)
{
	int num = 0, num2 = 0;
	scanf("%d %d", &num, &num2);
	int result = prime(num, num2);
	printf("%d", result);
}