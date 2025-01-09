#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

char y[5];
char m[3];
char d[3];
char get[11];
int main(void)
{
	int year = 0, month = 0, day = 0, later = 0;
	scanf("%s", get);
	getchar();
	strncpy(y, get, 4); y[4] = '\0'; year = atoi(y);
	strncpy(m, get + 5, 2); m[2] = '\0'; month = atoi(m);
	strncpy(d, get + 8, 2); d[2] = '\0'; day = atoi(d);
	scanf("%d", &later);
	day += later;
	while (1)
	{
		if (day < 31)
		{
			break;
		}
		if (day > 30)
		{
			month++;
			day -= 30;
		}
		if (month > 12)
		{
			month -= 12;
			year++;
		}
	}
	printf("%04d-%02d-%02d", year, month, day);
}