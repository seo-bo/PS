#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int basi = 0;
	int basf = 0;
	int count = 0;
	scanf("%d %d", &num1, &num2);
	int arr[100];
	for (int i = 0; i < num1; i++)
	{
		arr[i] = 0;
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%d %d %d", &basi, &basf, &count);
		for (int j = basi-1; basi-1 <= basf-1; basi++)
		{
				arr[basi -1] = count;	
		}
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d ", arr[i]);
	}
}
