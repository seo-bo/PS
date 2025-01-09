#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char ary[31] = { '\0' };
	int num = 0, form = 0, result = 0, i= 0;
	scanf("%d %d", &num, &form);
	while (num >0)
	{
		int put = num % form;
		if (put >= 10)
		{
			ary[i] = put - 10 + 'A';
		}
		else 
		{
			ary[i] = put + '0';
		}
		num = num / form;
		i++;
	}
	int size = strlen(ary);
	for (int i = size-1; i >= 0; i--)
	{
			printf("%c", ary[i]);
	}
}

