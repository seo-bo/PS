#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <memory.h>
int main(void)
{
	char ary[257];
	while (1)
	{
		int count = 0;
		fgets(ary, sizeof(ary), stdin);
		if (ary[0] == '#')
		{
			break;
		}
		for (int i = 0; i < strlen(ary); i++)
		{
			if (ary[i] == 'a' || ary[i] == 'e' || ary[i] == 'i' || ary[i] == 'o' || ary[i] == 'u' || ary[i] == 'A' || ary[i] == 'E' || ary[i] == 'I' || ary[i] == 'O' || ary[i] == 'U')
			{
				count++;
			}
		}
		printf("%d\n", count);
		memset(ary, sizeof(ary), '\0');
	}
}
