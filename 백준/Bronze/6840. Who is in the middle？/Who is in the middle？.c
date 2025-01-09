#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int ary[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			if (ary[i] < ary[j])
			{
				int temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
	printf("%d", ary[1]);
}