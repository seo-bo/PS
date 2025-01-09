#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	
	scanf("%d", &num1);

	if (90 <= num1 && num1 <= 100)

		printf("A");
	else if (80 <= num1 && num1 < 90)
		printf("B");
	else if (70 <= num1 && num1 < 80)
		printf("C");
	else if (60 <= num1 && num1 < 70)
		printf("D");
	else
		printf("F");
}
