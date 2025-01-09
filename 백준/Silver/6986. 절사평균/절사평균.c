#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int compare(const void* num1, const void* num2)
{
	if (*(double*)num1 > *(double*)num2)
	{
		return 1;
	}
	else if (*(double*)num1 < *(double*)num2)
	{
		return -1;
	}
	else
		return 0;
}
int main(void)
{
	int num = 0, count = 0;
	double prim = 0, adj = 0;
	scanf("%d %d", &num, &count);
	double* ary = (double*)malloc(sizeof(double) * num);
	for (int i = 0; i < num; i++)
	{
		scanf("%lf", &ary[i]);
	}
	qsort(ary, num, sizeof(double), compare);
	for (int i = count; i <= num - 1 - count; i++)
	{
		prim += ary[i];
	}
	for (int i = 0; i < count; i++)
	{
		ary[i] = ary[count];
		ary[num - 1 - i] = ary[num - 1 - count];
	}
	for (int i = 0; i < num; i++)
	{
		adj += ary[i];
	}
	prim = (prim / (num - (count*2)));
	adj = (adj / num);

	printf("%.2lf\n", prim + 0.00000001);
	printf("%.2lf", adj + 0.00000001);
}
