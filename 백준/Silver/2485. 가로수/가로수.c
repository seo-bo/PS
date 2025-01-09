#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int* ary, int size)
{
	int result = ary[0];
	for (int i = 0; i < size-1; i++)
	{
	  result = gcdd(result, ary[i + 1]);
	  if (result == 1)
		{
			break;
		}
	}
	return result;
}

int gcdd(int num1, int num2)
{
	int temp = -1;
	while (1)
	{
		temp = (num2 % num1);
		if (temp == 0)
		{
			break;
		}
		num2 = num1;
		num1 = temp;
	}
	return num1;
}

int main(void)
{
	int num = 0, j =0;
	scanf("%d", &num);
	int* ary = (int*)malloc(sizeof(int) * num);
	int* bry = (int*)malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
		if (i > 0)
		{
			bry[j] = ary[i] - ary[i - 1];
			j++;
		}
	}
	int mul = gcd(bry, j);
	int result = ((ary[num - 1] - ary[0]) / mul + 1) - num;
	printf("%d",result);
}

