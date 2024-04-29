
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[10001];
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int get = 0;
		scanf("%d", &get);
		ary[get]++;
	}
	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0;j < ary[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}
