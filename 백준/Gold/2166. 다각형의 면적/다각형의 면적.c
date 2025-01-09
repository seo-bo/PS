#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
	int num = 0;
	double sum1 = 0, sum2 = 0;
	scanf("%d", &num);
	double** ary = malloc(sizeof(double*) * num);
	for (int i = 0; i < num; i++)
	{
		ary[i] = (double*)malloc(sizeof(double) * 2);
	}
	for (int i = 0; i < num; i++)
	{
		scanf("%lf %lf", &ary[i][0], &ary[i][1]);
	}
	for (int i = 0; i < num-1; i++)
	{
		sum1 += ary[i][0] * ary[i + 1][1];
		sum2 += ary[i][1] * ary[i + 1][0];
	}
	sum1 += ary[num - 1][0] * ary[0][1];
	sum2 += ary[num - 1][1] * ary[0][0];
	double result = fabs((sum1 - sum2) / 2);
	printf("%.1lf", result);
}