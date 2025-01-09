#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int arr[9];
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
	}
	int num2 = arr[0];
	int num3 = 1;
	for (int j = 1; j < 9; j++)
	{
		
		if (num2 < arr[j])
		{
			num2 = arr[j];
			num3 = j+1;
		}
		
	}
	printf("%d\n", num2);
	printf("%d", num3);

}
