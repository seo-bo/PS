
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	
	scanf("%d", &num1);
	scanf("%d", &num2);

	if (num1 > 0)
	{
		if (num2 > 0)
			printf("1");
		else
			printf("4");
	}
	else if (num1 < 0)
	{
		if (num2 > 0)
			printf("2");
		else
			printf("3");
	}
		
}
