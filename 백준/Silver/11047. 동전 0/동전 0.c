#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	int num = 0, money = 0, count = 0;
	scanf("%d %d", &num, &money);
	int* ary = malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	while (1)
	{
		if (money == 0)
		{
			break;
		}
		if ((money / ary[num - 1]) != 0)
		{
			count += money / ary[num - 1];
			money -= (money / ary[num - 1]) * ary[num - 1];
		}
		num--;
	}
	printf("%d", count);
}
