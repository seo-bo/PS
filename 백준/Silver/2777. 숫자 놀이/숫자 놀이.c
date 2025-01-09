#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int ary[8] = { 9,8,7,6,5,4,3,2 };
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int temp = 0, j = 0, count = 0;
		scanf("%d", &temp);
		while (1)
		{
			if (j == 8 || temp == 1)
			{
				break;
			}
			if (temp % ary[j] == 0)
			{
				temp /= ary[j];
				count++;
			}
			else
			{
				j++;
			}
		}
		if (temp != 1)
		{
			printf("%d\n", -1);
		}
		else if (temp == 1 && count == 0)
		{
			printf("%d\n", 1);
		}
		else
		{
			printf("%d\n", count);
		}
	}
}
