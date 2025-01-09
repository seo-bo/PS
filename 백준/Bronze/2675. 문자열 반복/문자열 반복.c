#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	int num1 = 0;
	int num2 = 0;
	char arr[20];
		scanf("%d", &num1);
		
		for (int k = 0; k < num1; k++)
		{
			scanf("%d %s", &num2, arr);
			for (int i = 0; i < strlen(arr); i++)
			{
				for (int j = 0; j < num2; j++)
					printf("%c", arr[i]);
			}
			printf("\n");
		}
	

}