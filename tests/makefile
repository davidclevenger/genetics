CC = gcc -std=c99
CFLAGS = -Wall -Wpedantic -Wextra -g

SRC = ../src
SRCS = $(SRC)/darwin.o $(SRC)/individual.o

TESTS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(TESTS)) 
PROGS = $(patsubst %.c, %, $(TESTS))


all: $(PROGS)

$(PROGS): %: %.o $(SRCS)
	$(CC) $(CFLAGS) $< $(SRCS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(SRC)

.PHONY:
clean:
	rm -rf $(OBJS) $(PROGS)
	rm -rf *.o 
