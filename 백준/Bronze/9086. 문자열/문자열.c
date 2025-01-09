#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char arr[1000];
	int num1 = 0;
	int count = 0;
	scanf("%d", &num1);
	
	for (int i = 0; i < num1; i++)
	{
		count = 0;
		for (int j = 0; j < 1000; j++)
		{
			arr[j] = 0;
		}
		scanf("%s", arr);

		for (int k = 0; k < 1000; k++)
		{
			
			if (arr[k] == 0)
			{
				break;
			}
			count++;
		}
		
		printf("%c%c\n",arr[0], arr[count - 1]);
		
	}
	
	
}
