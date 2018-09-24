CC = gcc
CFLAGS = -g
#SOURCE_FILE = $(wildcard *.c)
SOURCE_FILE = 	number-one-in-binary.c \
		insertsort.c \
		quicksort.c \
		replace-space.c \
		td-array.c
TREE_FILE = 	reconstruct-btree.c \
		non-recursive-traversebtree.c
LINKLIST_FILE = reverse-linklist.c \
		palindrome-list.c
TARGETS = $(SOURCE_FILE:%.c=%) $(TREE_FILE:%.c=%) $(LINKLIST_FILE:%.c=%)

.PHONY: all linklist btree clean

all: $(SOURCE_FILE) linklist btree
	@for name in $(SOURCE_FILE); \
	do \
		$(CC) $(CFLAGS) "$$name" -o `echo "$$name" | sed s/.c$$//g`; \
	done
linklist:
	@for name in $(LINKLIST_FILE); \
	do \
		$(CC) $(CFLAGS) linklist.c "$$name" -o `echo "$$name" | sed s/.c$$//g`; \
	done
btree:
	@for name in $(TREE_FILE); \
	do \
		$(CC) $(CFLAGS) btree.c "$$name" -o `echo "$$name" | sed s/.c$$//g`; \
	done
clean:
	rm -f $(TARGETS) *.out
