#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0, num2 = 0;
	while (scanf("%d %d", &num1, &num2) != EOF)
	{
		int result = 0;
		int stamp = 0;
		while (num1 != 0)
		{
			result += num1;
			stamp += num1;
			num1 = stamp / num2;
			stamp %= num2;
		}
		printf("%d\n", result);
	}
}