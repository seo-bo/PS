#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char ary[101];
int main(void)
{
	int len = 0, num = 0, size = 0, result = 0;
	scanf("%d %d", &len, &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		int get = 0;
		memset(ary, 0, sizeof(ary));
		gets(ary);
		size = strlen(ary);
		for (int j = 0; j < size; j++)
		{
			if (ary[j] >= 'A' && ary[j] <= 'Z')
			{
				get += 4;
			}
			else if (ary[j] >= 'a' && ary[j] <= 'z')
			{
				get += 2;
			}
			else if (ary[j] >= '0' && ary[j] <= '9')
			{
				get += 2;
			}
			else if (ary[j] <= ' ')
			{
				get++;
			}
		}
		if (get <= len)
		{
			result++;
		}
	}
	printf("%d", result);
}