#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

long long n = 0;
long long pizza[1000010] = { 0, }; // 피자 2배

typedef struct PZ
{
	long long hot;
	long long over;
}PZ;

typedef struct Node
{
	PZ data;
	struct Node* left;
	struct Node* right;
}Node;

Node* insert(Node* prev, PZ num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	return new;
}

void delete(Node* head, Node* removed)
{
	if (removed == head)
	{
		return;
	}
	removed->left->right = removed->right;
	removed->right->left = removed->left;
	free(removed);
}

int check(long long cen)
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->left = head->right = head;
	long long key = cen;
	for (int i = 1; i <= n; i++)
	{
		Node* p = head->left;
		if (pizza[i] > key) // 먹을 수 있다!
		{
			PZ temp = { pizza[i], pizza[i] - cen + key };
			insert(p, temp);
			key = cen;
		}
		else // 맵다
		{
			key += pizza[i];
			while (p != head && p->data.hot <= key)
			{
				Node* temp = p;
				p = p->left;
				key += temp->data.over;
				delete(head, temp);
			}
		}
	}
	if (head->left == head) // 다먹음
	{
		free(head);
		return 1;
	}
	else // 남김
	{
		Node* p = head->right;
		while (p != head)
		{
			Node* removed = p;
			p = p->right;
			delete(head,removed);
		}
		free(head);
		return 0;
	}
}

long long search(long long mmax)
{
	long long start = 0, end = mmax;
	while (start < end) // 하한과 상한 겹치면 return
	{
		long long cen = (start + end) / 2;
		if (check(cen))
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return start;
}

long long Max(long long num1, long long num2)
{
	return (num1 > num2) ? num1 : num2;
}

int main(void)
{
	long long mmax = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) // 1 2 3 4 말고 1 2 3 4 1 2 3 4면 어디에서 먹어도 가지않나?
	{
		scanf("%lld", &pizza[i]);
		pizza[i + n] = pizza[i];
		mmax = Max(mmax, pizza[i]);
	}
	n *= 2;
	printf("%lld", search(mmax));
}