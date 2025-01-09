#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
	int num = 0, result =0;
	scanf("%d", &num);
	for (int i = 1; i * i <= num; i++)
	{
		result++;
	}
	printf("%d", result);
}
