#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct Info
{
	int startm, startd;
	int endm, endd;
}Info;

int compare(const void* num1, const void* num2)
{
	if (((Info*)num1)->startm != ((Info*)num2)->startm)
	{
		return ((Info*)num1)->startm - ((Info*)num2)->startm;
	}
	else if (((Info*)num1)->startd != ((Info*)num2)->startd)
	{
		return ((Info*)num1)->startd - ((Info*)num2)->startd;
	}
	else if (((Info*)num1)->endm != ((Info*)num2)->endm)
	{
		return ((Info*)num1)->endm - ((Info*)num2)->endm;
	}
	else
	{
		return ((Info*)num1)->endd - ((Info*)num2)->endd;
	}
		
}

int main(void)
{
	int num = 0, count = 0, end = 301;
	scanf("%d", &num);
	Info* flower = (Info*)calloc(num, sizeof(Info));
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d %d %d", &flower[i].startm, &flower[i].startd, &flower[i].endm, &flower[i].endd);
		getchar();
	}
	qsort(flower, num, sizeof(Info), compare);
	int i = 0;
	while (end <= 1130)
	{
		int check = 0, max = 0;
		while (i < num && flower[i].startm * 100 + flower[i].startd <= end)
		{
			int temp = flower[i].endm * 100 + flower[i].endd;
			max = (temp > max) ? temp : max;
			i++;
			check = 1;
		}
		if (check == 0)
		{
			printf("0");
			return 0;
		}
		end = max;
		count++;
	}
	printf("%d", count);
}
