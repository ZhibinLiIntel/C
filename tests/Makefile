CC = gcc
CFLAGS = -g -O2
SOURCE_FILE = $(wildcard *.c)
TARGETS = $(SOURCE_FILE:%.c=%)

.PHONY: all clean
all: $(SOURCE_FILE)
	@for name in $(SOURCE_FILE); \
	do \
		$(CC) $(CFLAGS) "$$name" -o `echo "$$name" | sed s/.c$$//g`; \
	done
clean:
	rm -f $(TARGETS) *.out
