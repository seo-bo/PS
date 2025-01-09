#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	int count = 0;
	char arr[1000000];
	scanf("%[^\n]", arr);
	if (arr[0] != ' ')
		count++;
	for (int i = 1; i < strlen(arr); i++)
	{
		if (arr[i-1] == ' ' && arr[i] != ' ')
		{
			count++;
		}
	}
	printf("%d", count);
}