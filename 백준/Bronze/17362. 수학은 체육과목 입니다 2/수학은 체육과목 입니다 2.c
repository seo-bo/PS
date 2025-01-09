#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int result = num % 8;
	if (result == 1)
	{
		printf("%d", 1);
	}
	else if (result == 0 || result == 2)
	{
		printf("%d", 2);
	}
	else if (result == 3 || result == 7)
	{
		printf("%d", 3);
	}
	else if (result == 4 || result == 6)
	{
		printf("%d", 4);
	}
	else 
	{
		printf("%d", 5);
	}
}