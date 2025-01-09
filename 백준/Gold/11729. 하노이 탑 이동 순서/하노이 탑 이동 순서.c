#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int hanoi(int num, int from,int temp, int to)
{
	if (num == 1)
	{
		printf("%d %d\n", from, to);
	}
	else
	{
		hanoi(num - 1, from, to, temp);
		printf("%d %d\n", from, to);
		hanoi(num - 1, temp, from, to);
	}
}
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int result = pow(2, num) - 1;
	printf("%d\n", result);
	hanoi(num, 1, 2, 3);
}