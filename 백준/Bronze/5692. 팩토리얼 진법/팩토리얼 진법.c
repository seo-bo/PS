#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <ctype.h>

char str[6];
int facto[6] = {0,1,2,6,24,120};
int main(void)
{
	while (1)
	{
		memset(str, 0, sizeof(str));
		int num = 0, result = 0;
		scanf("%s", str);
		if (str[0] == '0')
		{
			break;
		}
		else
		{
			int size = strlen(str);
			int k = size;
			for (int i = 0; i < size; i++)
			{
				result += (int)(str[i] - '0') * facto[k];
				k--;
			}
			printf("%d\n", result);
		}
	}
}