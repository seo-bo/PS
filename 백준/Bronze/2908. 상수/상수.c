#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int count = 0;
	int num1 = 0;
	int num2 = 0;
	char arr[4];
	char brr[4];
	int crr[7];
	scanf("%s %s", arr, brr);

	int temp = arr[0];
	arr[0] = arr[2];
	arr[2] = temp;

	int temp2 = brr[0];
	brr[0] = brr[2];
	brr[2] = temp2;

	for (int i = 0; i < 3; i++)
	{
		crr[i] = (int)arr[i] - '0';
		num1 += crr[i]* pow(10, 2 - i);
	}
	for (int i = 0; i < 3; i++)
	{
		crr[i + 3] = (int)brr[i] - '0';
		num2 += crr[i+3] * pow(10, 2 - i);
	}
	if (num1 > num2)
	{
		printf("%d", num1);
	}
	else
	printf("%d", num2);

}