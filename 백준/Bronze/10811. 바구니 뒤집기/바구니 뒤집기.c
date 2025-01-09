#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1 = 0;
	int num2 = 0;
	int bas1 = 0;
	int bas2 = 0;
	int arr[100];
	scanf("%d %d", &num1, &num2);

	for (int i = 0; i < num1; i++)
	{

		arr[i] = i +1;
	}


	for (int i =0; i< num2; i++)
	{
		scanf("\n%d %d", &bas1, &bas2);
		int num3 = bas2 - bas1;
		for (int j = 0; j < (num3 + 1) / 2; j++)
		{
			int temp = arr[bas1 - 1];
			arr[bas1 - 1] = arr[bas2 - 1];
			arr[bas2 - 1] = temp;
			bas1 += 1;
			bas2 -= 1;
		}
		
	}
	for (int i = 0; i < num1; i++)
	{
		printf("%d ", arr[i]);
	}
	
}
