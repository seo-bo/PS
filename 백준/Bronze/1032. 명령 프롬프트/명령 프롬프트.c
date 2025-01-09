#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char search[101] = { '\0'};
char compare[101] = { '\0'};
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	fgets(search, sizeof(search), stdin);
	int size = strlen(search);
	while (num-1)
	{
		
		fgets(compare, sizeof(compare), stdin);
		for (int i = 0; i < size; i++)
		{
			
			if (search[i] != compare[i])
			{
				search[i] = '?';
			}
		}
		num--;
	}
	for (int i = 0; i < size; i++)
	{
		printf("%c", search[i]);
	}
}
