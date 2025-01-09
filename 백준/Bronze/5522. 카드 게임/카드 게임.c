#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int ary[5] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &ary[i]);
	}
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += ary[i];
	}
	printf("%d", sum);
}