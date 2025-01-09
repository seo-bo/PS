#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int ary[10001];

typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* create(int data)
{
	Tree* new = (Tree*)malloc(sizeof(Tree));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}

Tree* search(Tree* root, int key)
{
	if (root == NULL)
	{
		return create(key);
	}
	if (root->data > key)
	{
		root->left = search(root->left, key);
	}
	else if (root->data < key)
	{
		root->right = search(root->right, key);
	}
	return root;
}

void postorder(Tree* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}

int main(void)
{
	Tree* root = NULL;
	int i = 0;
	while (scanf("%d", &ary[i]) != EOF)
	{
		i++;
	}
	for (int j = 0; j < i; ++j)
	{
		root = search(root, ary[j]);
	}
	postorder(root);
}