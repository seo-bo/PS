#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int result = num;
	for(int k = 0; k< num; k++)
	{
		int count = 0;
		char ary[101] = {'/0',};
		scanf("%s", ary);
		int size = strlen(ary);
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j++)
			{
				if (ary[i] == ary[j+2])
				{
					if (ary[i + 1] != ary[j + 2])
					{
						count++;
					}
				}
			}
		}
		if (count != 0)
		{
			if (size != 1)
			{
				result--;
			}
		}
	}
	printf("%d", result);
}