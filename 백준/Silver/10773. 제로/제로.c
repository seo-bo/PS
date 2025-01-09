#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[100001] = { 0, };
int main(void)
{
	int num = 0, put = 0, where = 0, result =0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &put);
		if (put == 0)
		{
			where -= 1;
			ary[where] = 0;
		}
		else
		{
			ary[where] = put;
			where++;
		}
	}
	for (int i = 0; i < num; i++)
	{
		result += ary[i];
	}
	printf("%d", result);
}
