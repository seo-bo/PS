#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int result = 0;
	char arr[100];
	scanf("%d", &num1);
	scanf("%s", arr);
	for (int i = 0; i < num1; i++)
	{
		arr[i] = (int)arr[i] - 48;
	}
	for (int i = 0; i < num1; i++)
	{
		result += arr[i];
	}
	printf("%d", result);
}
