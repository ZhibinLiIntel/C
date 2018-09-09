#include <stdio.h>

struct node {
	int val;
	struct node *lchild;
	struct node *rchild;
};

typedef struct node *treenode;
