#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Key
{
	int number;
	char getkey[2];
	char getpass[11];
}Key;

int compare(const void* num1, const void* num2)
{
	return (*(Key*)num1).number - (*(Key*)num2).number;
}

int charcompare(const void* num1, const void* num2)
{
	if ((*(Key*)num1).getkey[0] == (*(Key*)num2).getkey[0])
	{
		return (*(Key*)num1).number - (*(Key*)num2).number;
	}
	else
	{
		return (*(Key*)num1).getkey[0] - (*(Key*)num2).getkey[0];
	}
}

char key[11];
char password[101];

int main(void)
{
	scanf("%s", key);
	int size = strlen(key);
	Key* get = (Key*)malloc(sizeof(Key) * size);
	for (int i = 0; i < size; i++)
	{
		get[i].number = i;
		get[i].getkey[0] = key[i];
	}
	qsort(get, size, sizeof(Key), charcompare);
	scanf("%s", password);
	int pass_size = strlen(password);
	int real_size = pass_size / size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < real_size; j++)
		{
			get[i].getpass[j] = password[i * real_size + j];
		}
	}
	qsort(get, size, sizeof(Key), compare);
	for (int i = 0; i < real_size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%c", get[j].getpass[i]);
		}
	}
	free(get);
}

