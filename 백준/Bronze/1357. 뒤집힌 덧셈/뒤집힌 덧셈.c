#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Rev(int num)
{
	int reversed = 0;
	while (num != 0)
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}
	return reversed;
}


int main(void)
{
	int X = 0, Y = 0;
	scanf("%d %d", &X, &Y);
	printf("%d", Rev(Rev(X) + Rev(Y)));
}