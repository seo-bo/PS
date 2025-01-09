#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	scanf("%d %d", &num1, &num2);
	double num3 = (double)num1 / (double)num2;

	printf("%.9lf", num3);
	
}
