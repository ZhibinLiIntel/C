#include "link_list-operations.h"

static bool
palindrome(listnode head)
{
	listnode slow = head;
	listnode fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	listnode prev = NULL;
	while (slow) {
		listnode tmp = slow->next;
		slow->next = prev;
		prev = slow;
		slow = tmp;
	}
	listnode forward = head;
	listnode backward = prev;
	while (!(forward == backward || forward->next == backward)) {
		if (forward->val != backward->val)
			return false;
		forward = forward->next;
		backward = backward->next;
	}
	return true;
}

int
main(void)
{
	listnode head = create_palindrome_list(4);
	display_list(head);
	bool test = palindrome(head);
	if (test)
		printf("palindrome\n");
	else
		printf("not palindrome\n");
	return 0;
}
