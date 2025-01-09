#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int result = 0;
	int ary[100][100] = {0,};
	int bry[100][100] = {0,};
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			scanf("%d", &bry[i][j]);
		}
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			printf("%d ",ary[i][j] + bry[i][j]);
		}
		printf("\n");
	}
}