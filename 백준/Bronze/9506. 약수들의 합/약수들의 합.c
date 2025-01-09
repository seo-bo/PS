#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	while (1)
	{
		int num = 0;
		int k = 0;
		int result = 0;
		scanf("%d", &num);
		if (num == -1)
		{
			break;
		}
		int arr[100001] = { 0, };
		for (int i = 1; i < num; i++)
		{
			if (num % i == 0)
			{
				arr[k] = i;
				k++;
			}
		}
		int size = sizeof(arr) / 4;
		for (int i = 0; i < k; i++)
		{
			result += arr[i];
		}
		
		if (result == num)
		{
			printf("%d = ", result);
			for (int i = 0; i < k; i++)
			{
				if (i < k - 1)
				{
					printf("%d + ", arr[i]);
				}
				else if (i == k - 1)
				{
					printf("%d\n", arr[i]);
				}
			}
		}
		else
			printf("%d is NOT perfect.\n", num);
	}
}