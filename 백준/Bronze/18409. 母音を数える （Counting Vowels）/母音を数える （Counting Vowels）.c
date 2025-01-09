#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	int count = 0;
	char ary[51];
	scanf("%s", ary);
	for (int i = 0; i < strlen(ary); i++)
	{
		if (ary[i] == 'a' || ary[i] == 'i' || ary[i] == 'u' || ary[i] == 'e' || ary[i] == 'o' )
		{
			count++;
		}
	}
	printf("%d", count);
}