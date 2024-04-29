#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char ary[51];
char result[51];

int head = -1;
int main(void)
{
	scanf("%s", ary);
	getchar();
	int size = strlen(ary);
	int count = 0;
	int i = 0;
	while(i < size)
	{
		count = 0;
		if (ary[i] == '.')
		{
			result[++head] = '.';
			i++;
		}
		else if (ary[i] == 'X')
		{
			while (ary[i] != '.' && i < size)
			{
				count++;
				i++;
			}
			if (count % 2 != 0)
			{
				printf("-1");
				return 0;
			}
			else
			{
				for (int i = 0; i < (count / 4) * 4; i++)
				{
					result[++head] = 'A';
				}
				for (int i = 0; i < (count % 4); i++)
				{
					result[++head] = 'B';
				}
			}
		}
	}
	printf("%s", result);
}
