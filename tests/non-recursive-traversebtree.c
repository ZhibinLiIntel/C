#include "defs.h"
#include <stdbool.h>

#define MAX 32

struct stack {
	int item[MAX];
	int top;
};
typedef struct stack *pstack;

static pstack
init_stack()
{
	pstack stack = (pstack)malloc(sizeof(struct stack));
	if (stack)
		stack->top = 0;
	return stack;
}

static void
push(pstack stack, int data)
{
	stack->item[stack->top++] = data;
}

static void
pop(pstack stack)
{
	if (stack->top == 0)
		return;
	stack->top--;
}

static bool
isempty(pstack stack)
{
	if (stack->top == 0)
		return true;
	return false;
}

static int
gettop(pstack stack)
{
	return stack->item[1];
}

static void
non_recursive_preorder(treenode tree)
{
	treenode stack[1000], node = tree;
	int top = 0;
	while (node || top) {
		if (node) {
			printf("%d ", node->val);
			stack[top++] = node;
			node = node->lchild;
		} else {
			node = stack[--top];
			node = node->rchild;
		}
	}
}

static void
non_recursive_postorder(treenode tree)
{
	treenode stack[1000], node = tree, r = NULL;
	int top = 0;
	while (node || top) {
		if (node) {
			stack[top++] = node;
			node = node->lchild;
		} else {
			node = stack[top - 1];
			if (node->rchild && node->rchild != r) {
				node = node->rchild;
				stack[top++] = node;
				node = node->lchild;
			} else {
				node = stack[--top];
				printf("%d ", node->val);
				r = node;
				node = NULL;
			}
		}
	}
}

int
main(void)
{
	int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	treenode tree = construct_binary_tree(pre, in);
	
	printf("non-recursive preorder traverse: ");
	non_recursive_preorder(tree);
	printf("\n");
	recursive_preorder(tree);

	printf("non-recursive postorder traverse: ");
	non_recursive_postorder(tree);
	printf("\n");
	recursive_postorder(tree);

	return 0;
}
