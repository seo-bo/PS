#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	double arr[1000];
	double result = 0;
	scanf("%d", &num1);

	for (int i = 0; i < num1; i++)
	{
		scanf("%lf", &arr[i]);
	}
	double num2 = arr[0];
	
	for (int i = 0; i < num1; i++)
	{
		if (num2 < arr[i])
		{
			num2 = arr[i];
		}
	}

	for (int i = 0; i < num1; i++)
	{
		arr[i] = (arr[i] / num2) * 100;
		result += arr[i];
		
	}
	
	printf("%.14lf\n", result / (double)num1);
	
}
