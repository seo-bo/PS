#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int num1 = 0, num2 = 0, k = 1;
	int div = 0, mul = 0;
	scanf("%d %d", &num1, &num2);
	if (num2 > num1)
	{
		int temp = num2;
		num2 = num1;
		num1 = temp;
	}
	for (int i = num2; i > 0; i--)
	{
		if (num1 % i == 0 && num2 % i ==0)
		{
			div = i;
			break;
		}
	}
	while (1)
	{
		if ((num1 * k) % num2 == 0)
		{
			mul = (num1 * k);
			break;
		}
		else
		{
			k++;
		}
	}
	printf("%d\n", div);
	printf("%d\n", mul);
}

