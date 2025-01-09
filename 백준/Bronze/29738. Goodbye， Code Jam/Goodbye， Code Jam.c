#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

int compare(int num)
{
	if (num > 4500)
	{
		return 1;
	}
	else if (num > 1000)
	{
		return 2;
	}
	else if (num > 25)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		int rank = 0;
		scanf("%d", &rank);
		getchar();
		int result = compare(rank);
		if (result != 0)
		{
			printf("Case #%d: Round %d\n", i + 1, result);
		}
		else
		{
			printf("Case #%d: World Finals\n", i + 1);
		}
	}
}