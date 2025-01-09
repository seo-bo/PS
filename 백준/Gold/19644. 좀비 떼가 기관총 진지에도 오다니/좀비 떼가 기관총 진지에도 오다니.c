#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	int street = 0, range = 0, dps = 0, bomb = 0;
	scanf("%d %d %d %d", &street, &range, &dps, &bomb);
	getchar();
	int* ary = (int*)malloc(sizeof(int) * (street + 1));
	int* prefix = (int*)malloc(sizeof(int) * (street + 1));
	prefix[0] = 0;
	for (int i = 1; i <= street; i++)
	{
		scanf("%d", &ary[i]);
		int temp = prefix[i - 1] - prefix[Max(0, i - range)] + dps;
		if (ary[i] <= temp)
		{
			prefix[i] = prefix[i - 1] + dps;
		}
		else
		{
			if (bomb != 0)
			{
				prefix[i] = prefix[i - 1];
				bomb--;
			}
			else
			{
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
}

