#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char arr[100];
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] <= 'Z' && arr[i] >= 'A')
		{
			arr[i] = (int)arr[i] + (int)('a' - 'A');
		}
	else if (arr[i] <= 'z' && arr[i] >= 'a')
		{
			arr[i] = (int)arr[i] - (int)('a' -'A');
		}
	}
	for (int i = 0; i < strlen(arr); i++)
	{
		printf("%c", arr[i]);
	}
}