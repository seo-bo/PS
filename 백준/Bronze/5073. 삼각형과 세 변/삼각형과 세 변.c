#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int max = 0;
	int min = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	if (num1 >= num2 && num1 >= num3)
	{
		max = num1;
		min = num2 + num3;
	}
	if (num2 >= num1 && num2 >= num3)
	{
		max = num2;
		min = num1 + num3;
	}
	if (num3 >= num2 && num3 >= num1)
	{
		max = num3;
		min = num2 + num1;
	}
	if (num1 == num2 && num1 == num3 && num3 == num2)
	{
		if (num1 == 0 && num2 == 0 && num3 == 0)
		{
			return 0;
		}
		else
			printf("Equilateral\n");
	}
	else if (max >= min)
	{
		printf("Invalid\n");
	}
	else if (num1 != num2 && num3 != num2 && num1 != num3)
	{
		printf("Scalene\n");
	}
	else
		
	printf("Isosceles\n");
	main();
}