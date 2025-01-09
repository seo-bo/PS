#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

double Min(double num1, double num2)
{
	return (num1 > num2) ? num2 : num1;
}

int main(void)
{
	double x1 = 0, y1 = 0, r1 = 0, x2 = 0, y2 = 0, r2 = 0;
	double d = 0, theta1 = 0, theta2 = 0, area1 = 0, area2 =0, result = 0;
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2);
	getchar();
	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	if (r1 + r2 <= d)
	{
		result = 0.0;
		printf("%.3lf", result);
		return 0;
	}
	else if (fabs(r1 - r2) >= d)
	{
		result = PI * Min(pow(r1, 2), pow(r2, 2));
		printf("%.3lf", result);
		return 0;
	}
	else
	{
		theta1 = 2.0 * acos((pow(r1, 2) + pow(d, 2) - pow(r2, 2)) / (2.0 * r1 * d));
		theta2 = 2.0 * acos((pow(r2, 2) + pow(d, 2) - pow(r1, 2)) / (2.0 * r2 * d));
		result = (0.5 * pow(r1, 2) * (theta1 - sin(theta1))) + (0.5 * pow(r2, 2) * (theta2 - sin(theta2)));
		printf("%.3lf", result);
		return 0;
	}
}
