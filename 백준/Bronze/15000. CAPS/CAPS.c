#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char arr[1000000];
	scanf("%s", arr);
	int size = strlen(arr);
	for (int i = 0; i < size; i++)
	{
		if (arr[i] <= 'Z' && arr[i] >= 'A')
		{
			arr[i] = arr[i] + ('a' - 'A');
		}
		else if (arr[i] >= 'a' && arr[i] <= 'z')
		{
			arr[i] = arr[i] - ('a' - 'A');
		}
		printf("%c", arr[i]);
	}
}