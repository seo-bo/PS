#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int num1 = 0, num2 = 0;
		scanf("%d %d", &num1, &num2);
		int temp = num2 - num1;
		int temp2 = (int)sqrt(temp);
		if (temp2 * temp2 == temp)
		{
			printf("%d\n", temp2 * 2 - 1);
		}
		else if (temp2 * temp2 < temp && temp <= temp2 * temp2 + temp2)
		{
			printf("%d\n", temp2 * 2);
		}
		else
		{
			printf("%d\n", temp2 * 2 + 1);
		}
	}
}