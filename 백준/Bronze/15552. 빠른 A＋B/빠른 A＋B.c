#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	scanf("%d", &num1);
	
	for (int i = 0; i < num1; i++)
	{
		int num2 = 0;
		int num3 = 0;
		scanf("%d %d", &num2, &num3);
		printf("%d\n",num2 + num3);
	}
	
}
