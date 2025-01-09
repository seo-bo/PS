#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int kurabe(int num)
{
	int value = 0;
	while (num)
	{
		num /= 10;
		value++;
	}
	return value;
}

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	int value = 0;
	scanf("%d %d", &num1, &num2);
	value = kurabe(num1);
	int count = 0;
	for (int i = 0; i < value; i++)
	{
		if (num1 % 10 == 8)
		{
			if (num2 - num1 == 0)
				count++;
		}
		num1 /= 10;
		num2 /= 10;
	}

	printf("%d", count);
}