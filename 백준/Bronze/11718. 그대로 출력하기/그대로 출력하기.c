#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory.h>
int main(void)
{
	char ary[100];
	while (fgets(ary, sizeof(ary), stdin) != NULL)
	{
		int size = strlen(ary);
		for (int i = 0; i < size; i++)
		{
			printf("%c", ary[i]);
		}
		memset(ary, '\0', sizeof(char) * size);
	}
}
