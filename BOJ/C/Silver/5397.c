#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

char get[1000001];

typedef struct Node
{
	char data;
	struct Node* left;
	struct Node* right;
}Node;

Node* key = NULL;


Node* init(Node* head)
{
	head->left = head->right = head;
	return head;
}

void insert(Node* prev, char num)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = num;
	new->left = prev;
	new->right = prev->right;
	prev->right->left = new;
	prev->right = new;
	key = new;
}

void delete(Node* head, Node* removed)
{
	if (head == removed)
	{
		return;
	}
	removed->right->left = removed->left;
	removed->left->right = removed->right;
	key = removed->left;
	free(removed);
}

int main(void)
{
	int test = 0;
	scanf("%d", &test);
	for (int i = 0; i < test; i++)
	{
		memset(get, 0, sizeof(get));
		Node* head = (Node*)malloc(sizeof(Node));
		key = init(head);
		scanf("%s", get);
		int size = strlen(get);
		for (int j = 0; j < size; j++)
		{
			if (get[j] == '<')
			{
				if (key != head)
				{
					key = key->left;
				}
			}
			else if (get[j] == '>')
			{
				if (key->right != head)
				{
					key = key->right;
				}
			}
			else if (get[j] == '-')
			{
				if (key != head)
				{
					delete(head, key);
				}
			}
			else
			{
				insert(key, get[j]);
			}
		}
		for (Node* k = head->right; k != head; k = k->right)
		{
			printf("%c", k->data);
		}
		printf("\n");
		Node* current = head->right;
		while (current != head) 
		{
			Node* next = current->right;
			free(current);
			current = next;
		}
		free(head);
	}
}
