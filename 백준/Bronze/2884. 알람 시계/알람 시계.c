#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	
	scanf("%d %d", &num1, &num2);
	int num3 = num1 * 60;
	int num4 = num3 + num2;
	int hour = (num4 - 45) / 60;
	int minute = (num4 - 45) % 60;
	if (num1 == 0 && num2 - 45 < 0)
		{
		num1 = 24;
		num3 = num1 * 60;
		num4 = num3 + num2;
		
			int hour = (num4 - 45) / 60;
			int minute = (num4 - 45) % 60;
			printf("%d %d", hour, minute);
		}
	else
		printf("%d %d", hour, minute);
	
	
}
