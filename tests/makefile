CC = gcc -std=c99
CFLAGS = -Wall -Wpedantic -g

SRC = ../src

default: tests

tests: $(SRC)/darwin.o $(SRC)/individual.o test.o
	$(CC) $(CFLAGS) $(SRC)/darwin.o $(SRC)/individual.o test.o -o test
	@echo "Built tests."

test.o: test.c
	$(CC) $(CFLAGS) -I $(SRC) -c test.c

clean:
	rm -rf *.o test
