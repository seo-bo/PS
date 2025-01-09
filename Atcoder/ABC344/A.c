#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char str[101];

int main(void)
{
	int count = 1;
	scanf("%s", str);
	getchar();
	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '|')
		{
			count = (count + 1) % 2;
		}
		if ('a'<= str[i] && str[i] <= 'z' && count == 1)
		{
			printf("%c", str[i]);
		}
	}
	return 0;
}
