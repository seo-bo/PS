#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	
	scanf("%d", &num1);

	if (num1 % 4 == 0)
	{
		if (num1 % 100 != 0 || num1 % 400 == 0)
			printf("1");
		else
			printf("0");
	}
	else
		printf("0");
		
}
