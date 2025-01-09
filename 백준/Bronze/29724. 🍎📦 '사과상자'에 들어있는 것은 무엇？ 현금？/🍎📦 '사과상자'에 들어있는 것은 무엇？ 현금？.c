#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
	int num = 0, apple = 0, box = 0;
	scanf("%d", &num);
	getchar();
	for (int i = 0; i < num; i++)
	{
		char get = 0;
		int w = 0, h = 0, l = 0;
		scanf("%c %d %d %d", &get, &w, &h, &l);
		getchar();
		if (get == 'A')
		{
			int num = (w / 12) * (h / 12) * (l / 12);
			apple += num * 4000;
			box += 1000 + (num * 500);
		}
		else if (get == 'B')
		{
			box += 6000;
		}
	}
	printf("%d\n%d", box, apple);
}