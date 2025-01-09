#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	char ary[101];
	int bry[7] = { 0, };
	int cry[7] = { 0, };
	scanf("%s", ary);
	int ALP = 0;
	int alp = 0;
	for (int i = 0; i < num; i++)
	{
		if (ary[i] == 'r')
		{
			bry[0] += 1;
		}
		else if (ary[i] == 'o')
		{
			bry[1] += 1;
		}
		else if (ary[i] == 'y')
		{
			bry[2] += 1;
		}
		else if (ary[i] == 'g')
		{
			bry[3] += 1;
		}
		else if (ary[i] == 'b')
		{
			bry[4] += 1;
		}
		else if (ary[i] == 'i')
		{
			bry[5] += 1;
		}
		else if (ary[i] == 'v')
		{
			bry[6] += 1;
		}

		if (ary[i] == 'R')
		{
			cry[0] += 1;
		}
		else if (ary[i] == 'O')
		{
			cry[1] += 1;
		}
		else if (ary[i] == 'Y')
		{
			cry[2] += 1;
		}
		else if (ary[i] == 'G')
		{
			cry[3] += 1;
		}
		else if (ary[i] == 'B')
		{
			cry[4] += 1;
		}
		else if (ary[i] == 'I')
		{
			cry[5] += 1;
		}
		else if (ary[i] == 'V')
		{
			cry[6] += 1;
		}
	}
	alp = bry[0];
	ALP = cry[0];
	for (int i = 0; i < 7; i++)
	{
		alp = alp * bry[i];
		ALP = ALP * cry[i];
	}
	if (alp == 0 && ALP == 0)
	{
		printf("NO!");
	} 
	else if (alp != 0 && ALP == 0)
	{
		printf("yes");
	}
	else if (alp == 0 && ALP != 0)
	{
		printf("YES");
	}
	else if (alp != 0 && ALP != 0)
	{
		printf("YeS");
	}
}
