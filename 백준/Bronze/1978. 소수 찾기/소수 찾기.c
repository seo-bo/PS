#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int prime = num;
	int ary[100];
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 0; i < num; i++)
	{
		int count = 0;
		for (int j = 1; j <= ary[i]; j++)
		{
			if (ary[i] % j == 0)
			{
				count++;
			}	
		}
		if (count != 2)
		{
			prime--;
		}
	}
	printf("%d", prime);
}