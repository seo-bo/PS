#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int count = 0;
	int arr[100];
	scanf("%d", &num1);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &num2);
	for (int i = 0; i < num1; i++)
	{
		
		if (arr[i] == num2)
		{
			count++;
		}
	}
	printf("%d", count);
}
