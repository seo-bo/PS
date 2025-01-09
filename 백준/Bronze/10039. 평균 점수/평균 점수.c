#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int result = 0;
	for (int i = 0; i < 5; i++)
	{
		int get = 0;
		scanf("%d", &get);
		if (get < 40)
		{
			result += 40;
		}
		else
		{
			result += get;
		}
	}
	printf("%d", result / 5);
}