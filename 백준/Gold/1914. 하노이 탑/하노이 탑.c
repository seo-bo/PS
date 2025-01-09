#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char ary[32] = { 0, };

void swap(char* num1, char* num2)
{
	char* temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void reverse(int size)
{
	for (int i = 0; i < size/2; i++)
	{
		swap(&ary[i], &ary[size - i - 1]);
	}
}

void hanoi(int num, int from, int temp, int to)
{
	if (num == 1)
	{
		printf("%d %d\n", from, to);
	}
	else
	{
		hanoi(num - 1, from, to, temp);
		printf("%d %d\n", from, to);
		hanoi(num - 1, temp, from, to);
	}
}

int main(void)
{
	int num = 0, carry = 0;
	long long count = 0;
	scanf("%d", &num);
	if (num <= 20)
	{
		count = pow(2, num) - 1;
		printf("%lld\n", count);
		hanoi(num, 1, 2, 3);
	}
	else
	{	
		int start = 20, end = num;
		count = pow(2, 20);
		sprintf(ary, "%lld", count);
		int size = strlen(ary);
		reverse(size);
		while (1)
		{
			if (start >= num)
			{
				break;
			}
			for (int i = 0; i < size; i++)
			{
				int temp = (ary[i] - '0') * 2 + carry;
				ary[i] = (temp % 10) + '0';
				carry = temp / 10;
			}
			if (carry > 0)
			{
				ary[size++] = carry + '0';
				carry = 0;
			}
			start++;
		}
		int new_size = strlen(ary);
		reverse(new_size);
		for (int i = 0; i < new_size; i++)
		{
			if (i == new_size - 1)
			{
				printf("%c", ary[i] - '0' - 1 + '0');
			}
			else
			{
				printf("%c", ary[i]);
			}
		}
		
	}
}
