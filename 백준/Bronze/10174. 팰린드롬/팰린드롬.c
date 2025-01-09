#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char ary[22];

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		int count = 0;
		memset(ary, 0, sizeof(ary));
		fgets(ary, 21, stdin);
		ary[strcspn(ary,"\n")] = '\0';
		int size = strlen(ary);
		int start = 0, end = size - 1;
		while(start <= end)
		{
			if (tolower(ary[start]) != tolower(ary[end]))
			{
				count++;
				break;
			}
			else
			{
				start++;
				end--;
			}
		}
		if (count != 0)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
	}
}