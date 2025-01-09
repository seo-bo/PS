#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;

	scanf("%d %d", &num1, &num2);
	int num3 = (num2 % 100) % 10;
	int num4 = ((num2 % 100) - num3);
	printf("%d\n", (num1 * num3));
	printf("%d\n", (num1 * num4)/10);
	printf("%d\n", (num1 * (num2 - num3 -num4)) / 100);
	printf("%d\n", num1 * num2);

}
