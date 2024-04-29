#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int mini = 0;
	
	scanf("%d %d %d %d", &num1, &num2, &num3, &num4 );
	mini = num1;
	if (mini > num2)
	{
		mini = num2;
	}
	if (mini > num3 - num1)
	{
		mini = num3 - num1;
	}
	if (mini > num4 - num2)
	{
		mini = num4 - num2;
	}
	printf("%d", mini);

}
