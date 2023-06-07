CC=gcc
CFLAGS=-Wall -Wextra -g
LFLAGS=-g
SRCS=main.c
OBJS=main.o
BIN=main

.PHONY: all
all: $(BIN)
	./$(BIN)

$(BIN): $(OBJS) 
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean 
clean:
	rm -rf $(BIN) $(OBJS)
