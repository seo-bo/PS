#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	
	scanf("%d %d %d", &num1, &num2, &num3);
	if (num1 == num2 && num1 == num3 && num2 == num3 )
	{
		printf("%d", num1 * 1000 + 10000);
	}
	else if (num1 != num2 && num1 != num3 && num2 != num3)
	{
		if (num1 > num2 && num1 > num3)
		printf("%d", num1 * 100);
		else if (num2 > num1 && num2 > num3)
			printf("%d", num2 * 100);
		else if (num3 > num1 && num3 > num2)
			printf("%d", num3 * 100);
	}
	else
	{
		if (num1 == num2)
			printf("%d", 1000 + num1 * 100);
		else if (num1 == num3)
			printf("%d", 1000 + num3 * 100);
		else if (num2 == num3)
			printf("%d", 1000 + num2 * 100);
	}
}

