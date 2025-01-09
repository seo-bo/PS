#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;
	char ary[3];
	scanf("%s", ary);
	for (int i = 0; i < 2; i++)
	{
		ary[i] = (int)ary[i] - '0';
	}
	if (ary[1] == '\0' - '0')
	{
		ary[1] = ary[0];
		ary[0] = 0;
	}
	int f0 = ary[0];
	int f1 = ary[1];
	int temp = ary[1];
	ary[1] = ary[0] + ary[1];
	if (ary[1] > 9)
	{
		ary[1] = ary[1] - 10;
	}
	ary[0] = temp;
	count++;
	while (1)
	{
		if (ary[0] == f0 && ary[1] == f1)
		{
			break;
		}
		if (ary[1] == '\0' - '0')
		{
			ary[1] = ary[0];
			ary[0] = 0;
		}
		int temp = ary[1];
		ary[1] = ary[0] + ary[1];
		if (ary[1]>9)
		{
			ary[1] = ary[1] - 10;
		}
		ary[0] = temp;
		count++;
	}
	printf("%d", count);	
}
