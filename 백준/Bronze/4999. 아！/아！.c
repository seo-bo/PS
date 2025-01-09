#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char ary[1000];
	char bry[1000];
	scanf("%s", ary);
	scanf("%s", bry);
	if (strlen(ary) < strlen(bry))
	{
		printf("no");
	}
	else
		printf("go");
}