#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	
	for (int i = 5; i <= num1; i += 4)
	{
		printf("long ");
	}
	printf("long int");
}
