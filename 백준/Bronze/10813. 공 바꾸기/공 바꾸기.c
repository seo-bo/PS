#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int bas1 = 0;
	int bas2 = 0;
	scanf("%d %d", &num1, &num2);
	int arr[100];
	for (int i = 0; i < num1; i++)
	{
		arr[i] = i+1;
	}
	for (int i = 0; i < num2; i++)
	{
		scanf("%d %d", &bas1, &bas2);
		int temp = arr[bas1-1];
		arr[bas1-1] = arr[bas2-1];
		arr[bas2-1] = temp;
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d ", arr[i]);
	}
}
