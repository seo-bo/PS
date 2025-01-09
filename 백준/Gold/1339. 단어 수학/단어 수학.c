#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <memory.h>

typedef struct Word
{
	char str[9];
	int len;
}Word;

typedef struct Alpha
{
	int count;
	int order;
	int final;
}Alpha;

int compare(const void* num1, const void* num2)
{
	return (*(Word*)num2).len - (*(Word*)num1).len;
}

int compare1(const void* num1, const void* num2)
{
	return (*(Alpha*)num2).count - (*(Alpha*)num1).count;
}

int compare2(const void* num1, const void* num2)
{
	return (*(Alpha*)num1).order - (*(Alpha*)num2).order;
}


int main(void)
{
	int num = 0, cod = 9, result = 0;
	scanf("%d", &num);
	Word* Sum = (Word*)malloc(sizeof(Word) * num);
	Alpha* alphacount = (Alpha*)malloc(sizeof(Alpha) * 27);
	memset(alphacount, 0, sizeof(Alpha)*27);
	for (int i = 0; i < num; i++)
	{
		scanf("%s", Sum[i].str);
		Sum[i].len = strlen(Sum[i].str);
	}
	qsort(Sum, num, sizeof(Word), compare);
	for (int i = 0; i < 27; i++)
	{
		alphacount[i].order = i;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < strlen(Sum[i].str);j++)
		{
			int getal = ((int)Sum[i].str[j] - (int)'A');
			alphacount[getal].count += pow(10, (strlen(Sum[i].str)-j-1));
		}
	}
	qsort(alphacount, 27, sizeof(Alpha), compare1);
	for (int i = 0; i < 27; i++)
	{
		if (alphacount[i].count != 0)
		{
			alphacount[i].final = cod;
			cod--;
		}
	}
	qsort(alphacount, 27, sizeof(Alpha), compare2);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < strlen(Sum[i].str); j++)
		{
			int getal = ((int)Sum[i].str[j] - (int)'A');
			result += alphacount[getal].final * pow(10, strlen(Sum[i].str) - j - 1);
		}
	}
	printf("%d", result);
}