#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	while(scanf("%d %d", &num1, &num2) != EOF)
	{
		
		printf("%d\n", num1 + num2);
		
	}
	return 0;
}
