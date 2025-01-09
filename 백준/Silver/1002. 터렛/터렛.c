#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int test = 0;
	double r1x = 0, r1y = 0, r1 = 0, r2x = 0, r2y = 0, r2 = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &r1x, &r1y, &r1, &r2x, &r2y, &r2);
		double distance = sqrt(pow((r1x - r2x), 2) + pow((r1y - r2y), 2));
		if (r1 < r2)
		{
			double temp = r1;
			r1 = r2;
			r2 = temp;
		}
		if (distance == 0 && r1 == r2)
		{
			printf("%d\n", -1);
		}
		else if (r1 + r2 == distance || r1 - r2 == distance)
		{
			printf("%d\n", 1);
		}
		else if (r1 + r2 > distance && r1 - r2 < distance)
		{
			printf("%d\n", 2);
		}
		else
			printf("%d\n", 0);
	}
}