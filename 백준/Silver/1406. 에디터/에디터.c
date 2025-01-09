#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char o_o[100001];

typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
}Node;

Node* rear = NULL;

void init(Node* head)
{
	head->left = head;
	head->right = head;
	rear = head;
}

void insert(char num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = rear;
	new->right = NULL;
	rear->right = new;
	rear = new;
}

void test_insert(char num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = rear;
	if (rear->right != NULL)
	{
		new->right = rear->right;
		rear->right->left = new;
		rear->right = new;
	}
	else
	{
		new->right = NULL;
		rear->right = new;
	}
	rear = new;
}

void delete(Node* head, Node* removed)
{
	if (head == removed)
	{
		return;
	}
	removed->left->right = removed->right;
	if (removed->right != NULL)
	{
		removed->right->left = removed->left;
	}
	free(removed);

}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	scanf("%s", o_o);
	getchar();
	int size = strlen(o_o);
	for (int i = 0; i < size; i++)
	{
		insert(o_o[i]);
	}
	int test = 0;
	scanf("%d", &test);
	getchar();
	for (int i = 0; i < test; i++)
	{
		char get;
		scanf("%c", &get);
		getchar();
		if (get == 'P')
		{
			char temp;
			scanf("%c", &temp);
			getchar();
			test_insert(temp);
		}
		else if (get == 'L')
		{
			if (rear->left != NULL)
			{
				rear = rear->left;
			}
		}
		else if (get == 'D')
		{
			if (rear->right != NULL)
			{
				rear = rear->right;
			}
		}
		else if (get == 'B')
		{
			if (rear != head)
			{
				Node* removed = rear;
				rear = rear->left;
				delete(head, removed);
			}
		}
	}
	for (Node* p = head->right; p != NULL; p = p->right)
	{
		printf("%c", p->data);
	}
}
