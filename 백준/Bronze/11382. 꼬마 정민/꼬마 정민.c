#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	 unsigned long long num1 = 0;
	 unsigned long long num2 = 0;
	 unsigned long long num3 = 0;
	scanf("%llu %llu %llu", &num1, &num2, &num3);
	
	printf("%llu\n", num1 + num2 + num3);
	
}
