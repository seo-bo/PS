#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	while (num > 0)
	{
		int money = 0,qu = 0, di = 0, ni = 0, pe = 0;
		scanf("%d", &money);
		qu = money / 25;
		money -= qu * 25;
		di = money / 10;
		money -= di * 10;
		ni = money / 5;
		money -= ni * 5;
		pe = money;
		printf("%d %d %d %d\n", qu, di, ni, pe);
		num--;
	}
}

