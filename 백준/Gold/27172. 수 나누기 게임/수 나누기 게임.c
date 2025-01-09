#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Card
{
	int idx;
	int have;
	int result;
}Card;

Card card[1000001];
int ary[100001] = { 0, };

int compare(const void* num1, const void* num2)
{
	if (((Card*)num1)->have < ((Card*)num2)->have)
	{
		return 1;
	}
	else if (((Card*)num1)->have > ((Card*)num2)->have)
	{
		return -1;
	}
	else
	{
		return ((Card*)num1)->idx - ((Card*)num2)->idx;
	}
}

int main(void) 
{
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		scanf("%d", &ary[i]);
		card[ary[i]].have = 1;
		card[ary[i]].idx = i;
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = ary[i] * 2; j < 1000001; j += ary[i])
		{
			if (card[j].have == 1)
			{
				card[ary[i]].result++;
				card[j].result--;
			}
		}
	}
	qsort(card, 1000001, sizeof(Card), compare);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", card[i].result);
	}
}