#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1;
	scanf("%d", &num1);
	int arr[1000001];
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &arr[i]);
	}
	int num2 = arr[0];
	int num3 = arr[0];
	for (int i = 0; i < num1; i++)
	{
		if (arr[i] < num2)
		{
			num2 = arr[i];
		}
		if (num3 < arr[i])
		{
			num3 = arr[i];
		}
	}
	printf("%d %d", num2, num3);
}
