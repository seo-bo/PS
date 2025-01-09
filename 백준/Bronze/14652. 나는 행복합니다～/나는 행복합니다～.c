#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	scanf("%d %d %d", &num1, &num2, &num3);
	int row = num3 / num2;
	int col = num3 % num2;
	printf("%d %d", row, col);
}