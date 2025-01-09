#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int result = 0;
	while (1)
	{
		int temp = 0;
		scanf("%d", &temp);
		if (temp == -1)
		{
			break;
		}
		result += temp;
	}
	printf("%d", result);
}