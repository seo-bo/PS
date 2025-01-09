#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int temp = 0;
		scanf("%d", &temp);
		result += temp;
	}
	int hour = result / 60;
	int minute = result % 60;
	printf("%d\n%d", hour, minute);
}