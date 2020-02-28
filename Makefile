.POSIX:

CFLAGS = -std=c99 -g -pedantic -Wall -Weverything

TESTS = test_intrep
all : $(TESTS)

clean :
	find . -maxdepth 1 -perm -111 -type f -exec rm {} +
	rm -f *.o

test_intrep : test_intrep.c intrep.o
	$(CC) $(CFLAGS) test_intrep.c intrep.o -o test_intrep $(LDFLAGS)

intrep.o : intrep.c intrep.h
