#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int *ary = malloc(sizeof(int) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i+1; j < num; j++)
		{
			if (ary[i] > ary[j])
			{
				int temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d\n", ary[i]);
	}
	free(ary);
}
