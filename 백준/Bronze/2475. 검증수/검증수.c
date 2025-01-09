#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int ary[5] = { 0, };
	int sum = 0;
	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		sum += pow(ary[i], 2);
	}
	result = sum % 10;
	printf("%d", result);
}