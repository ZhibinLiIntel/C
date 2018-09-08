#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct node {
	int val;
	struct node *lchild;
	struct node *rchild;
};

typedef struct node *treenode;

void
_recursive_preorder(treenode tree)
{
	if (tree == NULL)
		return;
	printf("%d ", tree->val);
	_recursive_preorder(tree->lchild);
	_recursive_preorder(tree->rchild);
}

#define recursive_preorder(tree) \
	do { \
		printf("pre-order: "); \
		_recursive_preorder(tree); \
		printf("\n"); \
	} while(0)

void
_recursive_inorder(treenode tree)
{
	if (tree == NULL)
		return;
	_recursive_inorder(tree->lchild);
	printf("%d ", tree->val);
	_recursive_inorder(tree->rchild);
}

#define recursive_inorder(tree) \
	do { \
		printf("in-order: "); \
		_recursive_inorder(tree); \
		printf("\n"); \
	} while(0)

void
_recursive_postorder(treenode tree)
{
	if (tree == NULL)
		return;
	_recursive_postorder(tree->lchild);
	_recursive_postorder(tree->rchild);
	printf("%d ", tree->val);
}

#define recursive_postorder(tree) \
	do { \
		printf("post-order: "); \
		_recursive_postorder(tree); \
		printf("\n"); \
	} while(0)
