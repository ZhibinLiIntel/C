#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>

typedef struct node {
	int val;
	struct node *next;
} *listnode;

listnode
create_list(int num)
{
	if (!num)
		return NULL;
	listnode head = malloc(sizeof(struct node));
	head->val = 0;
	head->next = NULL;

	if (num == 1)
		return head;

	listnode p = head;
	for (unsigned int i = 1; i < num; i++) {
		listnode new = malloc(sizeof(struct node));
		new->val = i;
		new->next = NULL;
		p->next = new;
		p = new;
	}
	return head;
}

listnode
create_palindrome_list(int num)
{
	if (!num)
		return NULL;
	listnode head = malloc(sizeof(struct node));
	head->val = 0;
	head->next = NULL;

	if (num == 1)
		return head;

	listnode p = head;
	unsigned int i = 1;
	for (; i < num; i++) {
		listnode new = malloc(sizeof(struct node));
		new->val = i;
		new->next = NULL;
		p->next = new;
		p = new;
	}
	int j;
#ifdef ODD
	j = i - 2;
#else
	j = i - 1;
#endif
	for (; j >= 0; j--) {
		listnode palindrome = malloc(sizeof(struct node));
		palindrome->val = j;
		palindrome->next = NULL;
		p->next = palindrome;
		p = palindrome;
	}
	return head;
}

void
display_list(listnode head)
{
	if (!head) {
		printf("Empty linked list!\n");
		return;
	}
	while (head) {
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n");
}
