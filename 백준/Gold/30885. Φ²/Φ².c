#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	long long data;
	long long space;
	struct Node* left;
	struct Node* right;
}Node;

void init(Node* head)
{
	head->left = head;
	head->right = head;
}

void insert(Node* prev, long long num, long long num2)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->space = num2;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
}

void eat(Node* head, Node* removed)
{
	if (removed == head)
	{
		return;
	}
	removed->left->right = removed->right;
	removed->right->left = removed->left;
	free(removed);
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	long long num = 0;
	scanf("%lld", &num);
	getchar();
	Node* p = head;
	for (long long i = 0; i < num; i++)
	{
		long long temp = 0;
		scanf("%lld", &temp);
		getchar();
		insert(p, temp, i + 1);
		p = p->right;
	}
	Node* q = head->right;
	while (num > 1)
	{
		if (q == head)
		{
			q = q->right;
			continue;
		}
		if (q->left != head && q->left->data <= q->data && q->right != head && q->right->data <= q->data) //양쪽 먹기
		{
			q->data += q->left->data + q->right->data;
			Node* temp = q->right;
			eat(head, q->left);
			eat(head, temp);
			num -= 2;
		}
		else if (q->left != head && q->left->data <= q->data)
		{
			q->data += q->left->data;
			eat(head, q->left);
			num--;
		}
		else if (q->right != head && q->right->data <= q->data)
		{
			q->data += q->right->data;
			eat(head, q->right);
			num--;
		}
		q = q->right;
	}
	printf("%lld\n%lld", head->right->data, head->right->space);
} 