#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	char ary[31] = { '\0' };
	scanf("%s", ary);
	int form = 0, result = 0;
	scanf("%d", &form);
	int size = strlen(ary);
	for (int i = 0; i < size; i++)
	{
		if (ary[i] >= '0' && ary[i] <= '9')
		{
			ary[i] = (int)ary[i] - '0';
		}
		else if (ary[i] >= 'A' && ary[i] <= 'Z')
		{
			ary[i] = (int)ary[i] - 'A' + 10;
		}
	}
	for (int i = 0; i < size; i++)
	{
		result += ary[size -1 - i] * pow(form, i);
	}
	printf("%d", result);
}

