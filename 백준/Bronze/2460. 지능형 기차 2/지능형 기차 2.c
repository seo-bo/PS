#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(void)
{
	int in[10] = { 0, };
	int out[10] = { 0, };
	int cur = 0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d", &out[i], &in[i]);
	}
	int co = in[0] - out[0];
	for (int i = 0; i < 10; i++)
	{
		cur = cur + in[i] - out[i];
		if (co < cur)
		{
			co = cur;
		}	
	}
	printf("%d", co);
}

