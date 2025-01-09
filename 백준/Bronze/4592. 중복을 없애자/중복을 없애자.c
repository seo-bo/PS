#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num = 0;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		int* ary = (int*)malloc(sizeof(int) * num);
		for (int i = 0; i < num; i++)
		{
			scanf("%d", &ary[i]);
		}
        for (int i = 0; i < num; i++)
        {
			if (ary[i] != ary[i + 1])
			{
				printf("%d ", ary[i]);
			}   
        }
        printf("$\n");
}
}

