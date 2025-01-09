#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void* num1, const void* num2)
{
	if (*(int*)num1 > *(int*)num2)
	{
		return 1;
	}
	if (*(int*)num1 < *(int*)num2)
	{
		return -1;
	}
	else
		return 0;

}

int bry[8001] = { 0, };
int cry[8001] = { 0, };
int main(void)
{
	int num = 0, total = 0, max = 0, mostnum = 0, k = 0, count = 0;
	scanf("%d", &num);
	int* ary = (int*)malloc(sizeof(int) * num);
	
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &ary[i]);
		total += ary[i];
	}
	qsort(ary, num, sizeof(int), compare);
	int avg = round((double)total / (double)num);
	int cen = floor(num / 2);
	for (int i = 0; i < num; i++)
	{
			bry[4000 + ary[i]]++;
	}
	for (int i = 4000 + ary[0]; i <= 4000 + ary[num - 1]; i++)
	{
		if (bry[i] > max)
		{
			max = bry[i];
		}
	}
	for (int i = 4000 + ary[0]; i <= 4000 + ary[num - 1]; i++)
	{
		if (bry[i] == max)
		{
			cry[k] = i - 4000;
			k++;
			count++;
		}
	}
	if (count>1)
	{
		mostnum = cry[1];
	}
	else if (count == 1)
	{
		mostnum = cry[0];
	}
	
	printf("%d\n", avg);
	printf("%d\n", ary[cen]);
	printf("%d\n", mostnum);
	printf("%d", ary[num - 1] - ary[0]);
}
