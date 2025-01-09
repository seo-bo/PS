#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	char arr[3];
	double credit = 0;
	scanf("%s", arr);
	if (arr[0] == 'A')
	{
		credit = 4.0;
	}
	else if (arr[0] == 'B')
	{
		credit = 3.0;
	}
	else if (arr[0] == 'C')
	{
		credit = 2.0;
	}
	else if (arr[0] == 'D')
	{
		credit = 1.0;
	}

	if (arr[1] == '+')
	{
		credit += 0.3;
	}
	else if (arr[1] == '-')
	{
		credit -= 0.3;
	}
	printf("%.1lf", credit);
}