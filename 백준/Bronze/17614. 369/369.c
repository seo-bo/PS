#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int count = 0;
	for (int i = 1; i <= num; i++)
	{
		char ary[6] = { 0, };
		sprintf(ary, "%d", i);
		for (int j = 0; ary[j] != '\0'; j++)
		{
			if (ary[j] == '3' || ary[j] == '6' || ary[j] == '9')
			{
				count++;
			}
		}
	}
	printf("%d", count);
}
