#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int top = -1;

int Max(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

void push(int* stack, int num)
{
	stack[++top] = num;
}

int lower_search(int* stack, int key, int size)
{
	int start = 0, end = size - 1;
	while (start < end)
	{
		int cen = (start + end) / 2;
		if (stack[cen] >= key)
		{
			end = cen;
		}
		else
		{
			start = cen + 1;
		}
	}
	return end;
}

typedef struct Node
{
	int data, LIS;
	struct Node* left;
	struct Node* right;
}Node;

Node* nodes[500001];

void init(Node* head)
{
	head->left = head->right = head;
}

Node* insert(Node* prev, int num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	return new;
}

void move_before(Node* x, Node* y)
{
	x->left->right = x->right;
	x->right->left = x->left;
	x->left = y->left;
	x->right = y;
	y->left->right = x;
	y->left = x;
}

void move_after(Node* x, Node* y)
{
	x->left->right = x->right;
	x->right->left = x->left;
	x->right = y->right;
	x->left = y;
	y->right->left = x;
	y->right = x;
}

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	Node* temp = NULL;
	init(head);
	int num = 0, test = 0, k = 0, new_top = -1, max = 0;
	scanf("%d %d", &num, &test);
	getchar();
	int* stack = (int*)calloc(num, sizeof(int));
	for (int i = 1; i <= num; i++)
	{
		if (i == 1)
		{
			temp = insert(head, i);
		}
		else
		{
			temp = insert(temp, i);
		}
		nodes[i] = temp;
	}
	for (int i = 0; i < test; i++)
	{
		char get;
		int num1 = 0, num2 = 0;
		scanf("%c %d %d", &get, &num1, &num2);
		getchar();
		switch (get)
		{
		case 'A':
		{
			move_before(nodes[num1], nodes[num2]);
			break;
		}
		case 'B':
		{
			move_after(nodes[num1], nodes[num2]);
			break;
		}
		}
	}
	for (Node* i = head->right; i != head; i = i->right)
	{
		if (i == head->right)
		{
			push(stack, i->data);
			i->LIS = 0;
		}
		else
		{
			int get = lower_search(stack, i->data, top + 1);
			if (stack[get] < i->data)
			{
				push(stack, i->data);
				i->LIS = get + 1;
			}
			else if (stack[get] >= i->data)
			{
				stack[get] = i->data;
				i->LIS = get;
			}
		}
	}
	printf("%d\n", num - (top + 1));
	free(stack);
	int* ary = (int*)calloc((num + 1), sizeof(int));
	for (Node* i = head->left; i != head; i = i->left)
	{
		if (top == i->LIS)
		{
			ary[i->data] = 1;
			max = Max(i->data, max);
			top--;
		}
	}
	for (int i = max; i <= num; i++)
	{
		if (ary[i] != 1)
		{
			printf("%c %d %d\n", 'B', i, i - 1);
		}
	}
	for (int i = max; i >= 1; i--)
	{
		if (ary[i] != 1)
		{
			printf("%c %d %d\n", 'A', i, i + 1);
		}
	}
}