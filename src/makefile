CC = gcc -std=c99
CFLAGS = -Wall -Wpedantic -g

default: test

# C build
test: individual.o darwin.o test.o
	$(CC) $(CFLAGS) individual.o darwin.o test.o -o test
	@echo "Done!"

individual.o: individual.h individual.c
	$(CC) $(CFLAGS) -c individual.h individual.c

darwin.o: darwin.h darwin.c
	$(CC) $(CFLAGS) -c darwin.h darwin.c

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -rf *.o *.gch test
