#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	
	while(1)
	{
		int num1 = 0;
		int num2 = 0;
		scanf("%d %d", &num1, &num2);
		if (num1 == 0 && num2 == 0)
			break;
		printf("%d\n", num1 + num2);
		
	}
	
}
