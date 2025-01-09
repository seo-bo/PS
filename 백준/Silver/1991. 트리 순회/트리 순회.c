#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct Tree
{
	char key;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* new_node(char key)
{
	Tree* new = malloc(sizeof(Tree));
	new->key = key;
	new->left = new->right = NULL;
	return new;
}

void insert(Tree* node, char key, char left_key, char right_key)
{
	if (node == NULL)
	{
		return;
	}
	if (node->key == key)
	{
		if (left_key != '.')
		{
			node->left = new_node(left_key);
		}
		if (right_key != '.')
		{
			node->right = new_node(right_key);
		}
	}
	else
	{
		insert(node->left, key, left_key, right_key);
		insert(node->right, key, left_key, right_key);
	}
}

void preorder(Tree* root)
{
	if (root != NULL)
	{
		printf("%c", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Tree* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c", root->key);
		inorder(root->right);
	}
}

void postorder(Tree* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->key);
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	Tree* root = new_node('A');
	for (int i = 0; i < num; i++)
	{
		char key, left_key, right_key;
		scanf(" %c %c %c", &key, &left_key, &right_key);
		insert(root, key ,left_key, right_key);
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
}
