#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		int finx = 0, finy = 0, initx = 0, inity = 0, num = 0, result = 0;
		scanf("%d %d %d %d", &initx, &inity, &finx, &finy);
		getchar();
		scanf("%d", &num);
		for (int j = 0; j < num; j++)
		{
			int x = 0, y = 0, r = 0, temp1 =0, temp2 =0;
			scanf("%d %d %d", &x, &y, &r);
			getchar();
			if (pow((initx - x), 2) + pow((inity - y), 2) < pow(r, 2))
			{
				temp1++;
			}
			if (pow((finx - x), 2) + pow((finy - y), 2) < pow(r, 2))
			{
				temp2++;
			}
			result += (int)pow((temp2 - temp1), 2);
		}
		printf("%d\n", result);
	}
}
