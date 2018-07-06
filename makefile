CC = gcc
CXX = g++
CFLAGS = -Wall -g

#default: test
default: c_test

#c++ build
#test: test.o darwin.o
	#$(CXX) $(CFLAGS) test.o darwin.o -o test 

#test.o: test.cpp
#	$(CXX) $(CFLAGS) -c test.cpp

#darwin.o: darwin.cpp darwin.hpp
	#$(CXX) $(CFLAGS) -c darwin.cpp darwin.hpp

#c build
c_test: c_test.o darwin.o
	$(CC) $(CFLAGS) test.o darwin.o -o c_test

darwin.o: darwin.h darwin.c
	$(CC) $(CFLAGS) -c darwin.c darwin.h

c_test.o: test.c
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -rf *.o *.gch test c_test
