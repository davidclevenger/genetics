CC = gcc -std=c99
CFLAGS = -Wall -Wpedantic -Wextra -g

SRC = ../src
SRCS = $(SRC)/darwin.o $(SRC)/individual.o

EXAMPS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(EXAMPS)) 
PROGS = $(patsubst %.c, %, $(EXAMPS))


all: $(PROGS)

$(PROGS): %: %.o $(SRCS)
	$(CC) $(CFLAGS) $< $(SRCS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(SRC)

.PHONY:
clean:
	rm -rf $(OBJS) $(PROGS)
	rm -rf *.o 
