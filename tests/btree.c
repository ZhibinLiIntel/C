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
