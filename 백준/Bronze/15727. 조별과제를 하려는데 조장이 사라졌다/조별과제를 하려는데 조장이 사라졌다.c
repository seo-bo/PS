#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	if (num % 5 == 0)
	{
		printf("%d", num / 5);
	}
	else
		printf("%d", (num / 5)+1);
}