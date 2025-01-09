#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char str[6];

int main(void)
{
	while (1)
	{
		int count = 0;
		memset(str, 0, sizeof(str));
		scanf("%s", str);
		getchar();
		if (str[0] == '0')
		{
			break;
		}
		int size = strlen(str);
		int k = size - 1;
		for (int i = 0; i < size; i++)
		{
			if (str[i] != str[k])
			{
				printf("no\n");
				count++;
				break;
			}
			else
			{
				k--;
			}
		}
		if (count == 0)
		{
			printf("yes\n");
		}
	}
}