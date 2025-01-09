#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int facto[10] = { 1,1, 2, 6, 24, 120 ,720, 5040, 40320, 362880 };
int password[10] = { 0, };
int exist[10] = { 0, };
int check[10] = { 0, };
int main(void)
{
	int len = 0, info = 0, time = 0, no = 0, pcount = 0, ecount = 0, c = 0, result = 0;
	scanf("%d %d %d %d", &len, &info, &time, &no);
	getchar();
	for (int i = 0; i < info; i++)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		if (a != 0)
		{
			if (password[a] == 0 && check[b] == 0)
			{
				password[a] = b;
				check[b] = 1;
				pcount++;
			}
		}
		else
		{
			if (exist[b] == 0 && check[b] == 0)
			{
				exist[b] = 1;
				check[b] = 1;
				ecount++;
			}
		}
	}
	int leftn = (9 - pcount - ecount), lefts = (len - pcount - ecount);
	c = facto[leftn] / facto[leftn - lefts];
	result = facto[lefts + ecount] / (facto[lefts]) * c;
	if (result % 3 == 0)
	{
		result = ((result / 3) * ((3 * time) + no)) - no;
	}
	else
	{
		int temp = (result % 3);
		result = (((result - temp) / 3) * ((3 * time) + no)) + (temp * time);
	}
	printf("%d", result);
}