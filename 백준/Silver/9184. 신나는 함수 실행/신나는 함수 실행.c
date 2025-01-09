#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ary[51][51][51] = { 0, };
int func(int num1, int num2, int num3)
{
	int result = 0;
	if (num1 <= 0 || num2 <= 0 || num3 <= 0)
	{
		return 1;
	}
	if (ary[num1][num2][num3] != 0)
	{
		return ary[num1][num2][num3];
	}
	else if (num1 > 20 || num2 > 20 || num3 > 20)
	{
		return ary[num1][num2][num3] = func(20, 20, 20);
	}
	else if (num1 < num2 && num2 < num3)
	{
		return ary[num1][num2][num3] = func(num1, num2, num3 - 1) + func(num1, num2 - 1, num3) - func(num1, num2 - 1, num3);
	}
	else
		return ary[num1][num2][num3] = func(num1 - 1, num2, num3) + func(num1 - 1, num2 - 1, num3) + func(num1 - 1, num2, num3 - 1) - func(num1 - 1, num2 - 1, num3 - 1);
}

int main(void)
{
	while (1)
	{
		int num1 = 0, num2 = 0, num3 = 0, result;
		scanf("%d %d %d", &num1, &num2, &num3);
		if (num1 == -1 && num2 == -1 && num3 == -1)
		{
			return 0;
		}
			result = func(num1, num2, num3);
			printf("w(%d, %d, %d) = %d\n", num1, num2, num3, result);
	}
}
