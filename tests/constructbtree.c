#include "btree.h"

treenode
reconstruct(int pre[], int in[], int len)
{
	if (len == 0)
		return NULL;

	treenode new = malloc(sizeof(struct node));
	new->val = pre[0];

	for (int i = 0; i < len; i++) {
		if (in[i] == pre[0]) {
			new->lchild = reconstruct(pre + 1, in, i);
			new->rchild = reconstruct(pre + 1 + i, in + i + 1, len - i - 1);
			break;
		}
	}

	return new;
}

#define reconstruct_binary_tree(pre, in) \
	reconstruct(pre, in, sizeof(in) / sizeof(int))
int
main(void)
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	treenode tree = reconstruct_binary_tree(pre, in);

	recursive_preorder(tree);
	recursive_inorder(tree);
	recursive_postorder(tree);

	return 0;
}
