CC = gcc -std=c99
CFLAGS = -Wall -Wpedantic -Wextra -g

# Coverage flags
CFLAGS += -fprofile-arcs -ftest-coverage
COV = -coverage


all: individual.o darwin.o 

individual.o: individual.h individual.c
	$(CC) $(CFLAGS) -c individual.h individual.c

darwin.o: darwin.h darwin.c
	$(CC) $(CFLAGS) -c darwin.h darwin.c

.PHONY:
clean:
	rm -rf *.o *.gch *.gcno *.gcda *.gcov
