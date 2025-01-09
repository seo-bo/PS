#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int init = 0;
	scanf("%d", &init);
	int fin = 0;
	scanf("%d", &fin);
	int l = 0;
	int k = 0;
	int size = fin - init +1;
	int ary[10001] = { 0, };
	int bry[10001] = { 0, };
	for (int i = init; i <= fin; i++)
	{
		ary[l] = i;
		l++;
	}
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 1; j <= ary[i]; j++)
		{
			if (ary[i] % j == 0)
			{
				count++;
			}
		}
		if (count == 2)
		{
			bry[k] = init + i;
			k++;	
		}
	}
	if (k == 0)
	{
		printf("%d", -1);
	}
	else
	{
		int sum = 0;
		int min = bry[0];
		for (int i = 0; i < k; i++)
		{
			sum += bry[i];
		}
		for (int i = 0; i < k; i++)
		{
			if (min >= bry[i])
			{
				min = bry[i];
			}
		}
		printf("%d\n", sum);
		printf("%d", min);
	}
}