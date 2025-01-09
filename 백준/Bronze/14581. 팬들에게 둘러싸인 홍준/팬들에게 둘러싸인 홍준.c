#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char ary[21];
	scanf("%s", ary);
	printf(":fan::fan::fan:\n");
	printf(":fan::");
	for (int i = 0; i < strlen(ary); i++)
	{
		printf("%c", ary[i]);
	}
	printf("::fan:\n");
	printf(":fan::fan::fan:");
}