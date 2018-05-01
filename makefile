CC = g++
CFLAGS = -Wall

default: test

test: test.o darwin.o
	$(CC) $(CFLAGS) test.o darwin.o -o test 

test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp

darwin.o: dawin.cpp darwin.hpp
	$(CC) $(CCFLAGS) -c darwin.cpp darwin.hpp
