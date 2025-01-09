#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ary[52];
int save[52] = { 0, };
int stack[52] = { 0, };
int head = 0;

int main(void) //https://latter2005.tistory.com/94의 도움을 받음.
{
	scanf("%s", ary);
	getchar();
	int size = strlen(ary);
	for (int i = 0; i < size; i++)
	{
		if (ary[i] == '(')
		{
			--stack[head];
			save[++head] = ary[i - 1] - '0';
		}
		else if (ary[i] == ')')
		{
			stack[head - 1] += save[head] * stack[head];
			stack[head--] = 0;
		}
		else
		{
			++stack[head];
		}
	}
	printf("%d", stack[0]);
}