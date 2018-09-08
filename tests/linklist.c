#include "link_list-operations.h"

int
main(void)
{
	listnode head = create_list(6);

	/* reverse */
	listnode prev = NULL;
	listnode curr = head;
	while (curr) {
		listnode tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	head = prev;

	display_list(head);
}
