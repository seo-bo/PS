#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char o_o[51];

int main(void)
{
	scanf("%s", o_o);
	getchar();
	int size = strlen(o_o);
	for (int i = 0; i < size; i++)
	{
		int check = 1;
		for (int j = 0; j < (size - i) / 2; j++)
		{
			if (o_o[i + j] != o_o[size - 1 - j])
			{
				check = 0;
				break;
			}
		}
		if (check)
		{
			printf("%d", size + i);
			return 0;
		}
	}
}
