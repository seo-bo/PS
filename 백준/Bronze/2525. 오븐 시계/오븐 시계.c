#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	
	scanf("%d %d", &num1, &num2);
	scanf("%d", &num3);
	int oven1 = num1 * 60; 
	int oven2 = oven1 + num2; 
	int oven3 = oven2 + num3; 
	int hour = (oven3) / 60;
	int minute = (oven3) % 60;
	if (oven3 > 1439)
		{
		int oven4 = oven3 - 1440;
		
		int hour = (oven4) / 60;
			int minute = (oven4) % 60;
			printf("%d %d", hour, minute);
		}
	else
		printf("%d %d", hour, minute);
	
	
}
