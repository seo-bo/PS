#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	char ary[10001];
	fgets(ary, sizeof(ary), stdin);
	int joi = 0;
	int ioi = 0;
	for (int i = 0; i < strlen(ary); i ++)
	{
		if (ary[i] == 'J' && ary[i + 1] == 'O' && ary[i+2] == 'I')
		{
			joi++;
		}
		else if (ary[i] == 'I' && ary[i + 1] == 'O' && ary[i + 2] == 'I')
		{
			ioi++;
		}
	}
	printf("%d\n%d", joi, ioi);
}
