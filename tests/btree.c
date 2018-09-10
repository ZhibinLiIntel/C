#include "defs.h"

void
_recursive_preorder(treenode tree)
{
	if (tree == NULL)
		return;
	printf("%d ", tree->val);
	_recursive_preorder(tree->lchild);
	_recursive_preorder(tree->rchild);
}

void
_recursive_inorder(treenode tree)
{
	if (tree == NULL)
		return;
	_recursive_inorder(tree->lchild);
	printf("%d ", tree->val);
	_recursive_inorder(tree->rchild);
}

void
_recursive_postorder(treenode tree)
{
	if (tree == NULL)
		return;
	_recursive_postorder(tree->lchild);
	_recursive_postorder(tree->rchild);
	printf("%d ", tree->val);
}

treenode
construct(int pre[], int in[], int len)
{
	if (len == 0)
		return NULL;

	treenode new = malloc(sizeof(struct node));
	new->val = pre[0];

	for (int i = 0; i < len; i++) {
		if (in[i] == pre[0]) {
			new->lchild = construct(pre + 1, in, i);
			new->rchild = construct(pre + 1 + i, in + i + 1, len - i - 1);
			break;
		}
	}

	return new;
}
