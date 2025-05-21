CC=gcc
CFLAGS=-W -Wall -Wextra -Werror -O2 -fsanitize=address
EXEC=trie

all: $(EXEC)

$(EXEC): trie.c
	$(CC) $(CFLAGS) -o $(EXEC) trie.c

run:
	./$(EXEC)

clean:
	rm -f $(EXEC)