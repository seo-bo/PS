#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int result = 0;
	int count = 0;
	int c_result = 0;
	int cc = 0;
	scanf("%d", &result);
	
	scanf("%d", &count);
	
	for (int i = 0; i < count; i++)
	{
		int value = 0;
		int num = 0;
		scanf("%d %d", &value, &num);
		cc = value * num;
		c_result += cc;
		
	}
	if (c_result == result)
	{
		printf("Yes");
	}
	else
		printf("No");
	
}
