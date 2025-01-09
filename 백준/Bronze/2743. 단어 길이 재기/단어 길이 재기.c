#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char arr[100];
	int num1 = 0;
	scanf("%s", arr);
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] == '\0')
		{
			break;
		}
		num1++;
	}
	printf("%d", num1);
	
}
