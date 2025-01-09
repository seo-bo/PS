#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
	printf("%d", (num1 * num2) + (num3 * num4));
}