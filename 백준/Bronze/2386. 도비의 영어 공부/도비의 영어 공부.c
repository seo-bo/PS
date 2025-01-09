#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>

char str[253];

int main(void)
{
	while (1)
	{
		int count = 0; char temp;
		memset(str, 0, sizeof(str));
		scanf("%c", &temp);
		getchar();
		fgets(str, 252, stdin);
		if (temp == '#')
		{
			break;
		}
		else
		{
			str[strcspn(str, "\n")] = '\0';
			int size = strlen(str);
			for (int i = 0; i < size; i++)
			{
				if (str[i] == temp || str[i] == toupper(temp))
				{
					count++;
				}
			}
			printf("%c %d\n", temp, count);
		}
		
	}
}