#include <stdlib.h>
#include <errno.h>
#include "linklist.h"
#include "btree.h"

extern listnode create_list(int num);
extern listnode create_palindrome_list(int num);
extern void display_list(listnode head);

extern void _recursive_preorder(treenode tree);
#define recursive_preorder(tree) \
	do { \
		printf("pre-order: "); \
		_recursive_preorder(tree); \
		printf("\n"); \
	} while(0)

extern void _recursive_inorder(treenode tree);
#define recursive_inorder(tree) \
	do { \
		printf("in-order: "); \
		_recursive_inorder(tree); \
		printf("\n"); \
	} while(0)

extern void _recursive_postorder(treenode tree);
#define recursive_postorder(tree) \
	do { \
		printf("post-order: "); \
		_recursive_postorder(tree); \
		printf("\n"); \
	} while(0)

extern treenode construct(int pre[], int in[], int len);
#define construct_binary_tree(pre, in) \
	construct(pre, in, sizeof(in) / sizeof(int))
