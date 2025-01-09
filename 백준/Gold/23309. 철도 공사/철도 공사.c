#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
}Node;

Node* nodes[1000001];

void init(Node* head)
{
	head->left = head->right = head;
	nodes[0] = head;
}

Node* insert(Node* prev, int num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	nodes[num] = new;
	return new;
}

int delete(Node* head, Node* removed)
{
	if (head == removed)
	{
		return -1;
	}
	int temp = removed->data;
	nodes[temp] = NULL;
	removed->right->left = removed->left;
	removed->left->right = removed->right;
	free(removed);
	return temp;
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	Node* temp = head;
	int subway = 0, test = 0;
	scanf("%d %d", &subway, &test);
	getchar();
	for (int i = 0; i < subway; i++)
	{
		int num = 0;
		scanf("%d", &num);
		getchar();
		temp = insert(temp, num);
	}
	for (int i = 0; i < test; i++)
	{
		char ary[3];
		scanf("%s", ary);
		if (strcmp("BN", ary) == 0)
		{
			int num1 = 0, num2 = 0;
			scanf("%d %d", &num1, &num2);
			getchar();
			Node* travel = nodes[num1]->right;
			if (travel == head)
			{
				travel = travel->right;
				printf("%d\n", travel->data);
			}
			else
			{
				printf("%d\n", travel->data);
			}
			insert(travel->left, num2);
		}
		else if (strcmp("BP", ary) == 0)
		{
			int num1 = 0, num2 = 0;
			scanf("%d %d", &num1, &num2);
			getchar();
			Node* travel = nodes[num1]->left;
			if (travel == head)
			{
				travel = travel->left;
				printf("%d\n", travel->data);
			}
			else
			{
				printf("%d\n", travel->data);
			}
			insert(travel, num2);
		}
		else if (strcmp("CN", ary) == 0)
		{
			int num1 = 0;
			scanf("%d", &num1);
			Node* travel = nodes[num1]->right;
			if (travel == head)
			{
				travel = travel->right;
				printf("%d\n",delete(head, travel));
			}
			else
			{
				printf("%d\n", delete(head, travel));
			}
		}
		else if (strcmp("CP", ary) == 0)
		{
			int num1 = 0;
			scanf("%d", &num1);
			Node* travel = nodes[num1]->left;
			if (travel == head)
			{
				travel = travel->left;
				printf("%d\n", delete(head, travel));
			}
			else
			{
				printf("%d\n", delete(head, travel));
			}
		}
	}
	free(head);
}