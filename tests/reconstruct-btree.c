#include "defs.h"

int
main(void)
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	treenode tree = construct_binary_tree(pre, in);

	recursive_preorder(tree);
	recursive_inorder(tree);
	recursive_postorder(tree);

	return 0;
}
