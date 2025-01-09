#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	
	int arr[10000];
	scanf("%d %d", &num1, &num2);
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < num1; i++)
	{
		
		if (arr[i] < num2)
		{
			printf("%d ", arr[i]);
		}
	}
	
}
