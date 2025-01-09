#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num = 0;
	int num2 = 0;
	while (scanf("%d %d", &num, &num2) !=EOF)
	{
		printf("%d\n", num2 / (num + 1));
	}
}