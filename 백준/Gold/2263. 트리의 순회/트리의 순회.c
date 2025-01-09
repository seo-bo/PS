#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

typedef struct Tree
{
	int key;
	struct Tree* left;
	struct Tree* right;
}Tree;

Tree* new_node(int key)
{
	Tree* new = malloc(sizeof(Tree));
	new->key = key;
	new->left = new->right = NULL;
	return new;
}

Tree* build(int* in, int* post, int instart, int inend, int* pindex, int * save)
{
	if (instart > inend)
	{
		return NULL;
	}
	Tree* node = new_node(post[*pindex]);
	int iindex = save[post[*pindex]];
	(*pindex)--;
	node->right = build(in, post, iindex + 1, inend, pindex, save);
	node->left = build(in, post, instart, iindex - 1, pindex, save);
	return node;
}

void preorder(Tree* root)
{
	if (root != NULL)
	{
		printf("%d ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(void)
{
	int num = 0;
	scanf("%d", &num);
	getchar();
	int* in = (int*)malloc(sizeof(int) * num);
	int* post = (int*)malloc(sizeof(int) * num);
	int* save = (int*)malloc(sizeof(int) * (num + 1));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &in[i]);
		getchar();
		save[in[i]] = i;
	}
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &post[i]);
		getchar();
	}
	int pindex = num - 1;
	Tree* root = build(in, post, 0, num - 1, &pindex, save);
	free(in);
	free(post);
	free(save);
	preorder(root);
}
